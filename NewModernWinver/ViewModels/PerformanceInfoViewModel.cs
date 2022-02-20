using NewModernWinver.Interop;
using NewModernWinver.Misc;
using RegistryRT;
using System;
using System.Net;
using System.Text;
using Windows.Storage;

namespace NewModernWinver.ViewModels
{
    public class PerformanceInfoViewModel : ViewModel
    {
        #region Interop
        public static SYSTEM_INFO SysInfo = new SYSTEM_INFO();
        private readonly MEMORYSTATUSEX mem = new MEMORYSTATUSEX();
        #endregion

        #region Private
        private int _cpuUsage;

        private double _usedRam;
        private double _freeRam;

        private double UsedRam
        {
            get => _usedRam;
            set
            {
                _usedRam = Math.Round(value, 2, MidpointRounding.AwayFromZero);
                OnPropertyChanged(nameof(UsedRamGB));
                OnPropertyChanged(nameof(UsedRamPercent));
            }
        }

        private double FreeRam
        {
            get => _freeRam;
            set
            {
                _freeRam = Math.Round(value, 2, MidpointRounding.AwayFromZero);
                OnPropertyChanged(nameof(FreeRamGB));
            }
        }

        private ulong TotalStorage { get; set; }
        private double UsedStorage { get; set; }
        private double FreeStorage { get; set; }
        #endregion

        public PerformanceInfoViewModel()
        {
            // No need to get this more than once
            SetPersistentInfo();
            Update();
        }

        #region Persistent properties
        public string SystemName { get; set; }

        public string CpuName { get; set; }
        public string CpuArch { get; set; }
        public string CpuClockSpeed { get; set; }
        public string CpuThreads { get; set; }

        public ulong TotalRam { get; set; }
        #endregion

        #region Processor
        public string CpuUsagePercent => CpuUsage.ToString() + "%";

        public int CpuUsage
        {
            get => _cpuUsage;
            set
            {
                Set(ref _cpuUsage, value);
                OnPropertyChanged(nameof(CpuUsagePercent));
            }
        }
        #endregion

        #region Memory
        public string TotalRamGB => TotalRam.ToString() + "GB";
        public string UsedRamGB => UsedRam.ToString() + "GB used";
        public string FreeRamGB => FreeRam.ToString() + "GB free";

        public double UsedRamPercent
        {
            get
            {
                double val = 0;
                try
                {
                    val = UsedRam / TotalRam * 100.0;
                }
                catch (DivideByZeroException) { }

                return val;
            }
        }
        #endregion

        #region Storage
        public string TotalStorageGB => TotalStorage.ToString() + "GB";
        public string UsedStorageGB => UsedStorage.ToString("N2") + "GB used";
        public string FreeStorageGB => FreeStorage.ToString("N2") + "GB free";

        public double UsedStoragePercent { get; set; }
        #endregion

        public void Update()
        {
            Imports.GlobalMemoryStatusEx(mem);

            UsedRam = (mem.ullTotalPhys - mem.ullAvailPhys) / 1048576.0 / 1024.0;
            FreeRam = TotalRam - UsedRam;

            CpuUsage = Convert.ToInt32(CpuUtil.GetPercentage());
        }

        private void SetPersistentInfo()
        {
            SystemName = Dns.GetHostName();

            // CPU data
            Imports.GetNativeSystemInfo(out SYSTEM_INFO sysInfo);
            CpuArch = ((Arch)sysInfo.CpuInfo.ProcessorArchitecture).ToString();
            CpuThreads = CpuUtil.ProcessorCount + " threads";

            Registry reg = new Registry();
            reg.InitNTDLLEntryPoints();

            reg.QueryValue(RegistryHive.HKEY_LOCAL_MACHINE, @"HARDWARE\DESCRIPTION\System\CentralProcessor\0", "ProcessorNameString", out uint RegType, out byte[] data);
            CpuName = Encoding.Unicode.GetString(data).Replace("\0", "").TrimEnd();

            reg.QueryValue(RegistryHive.HKEY_LOCAL_MACHINE, @"HARDWARE\DESCRIPTION\System\CentralProcessor\0", "~MHz", out RegType, out data);
            CpuClockSpeed = BitConverter.ToInt32(data, 0) + "MHz";

            // RAM data
            Imports.GlobalMemoryStatusEx(mem);
            var total = mem.ullTotalPhys / 1048576.0;
            TotalRam = (ulong)Math.Round(total / 1024.0);

            // Storage data
            IStorageFolder appFolder = ApplicationData.Current.LocalFolder;
            Imports.GetDiskFreeSpaceEx(appFolder.Path,
                out ulong freeBytesAvailable,
                out ulong totalNumberOfBytes,
                out ulong totalNumberOfFreeBytes);

            TotalStorage = totalNumberOfBytes / 1073741824;
            UsedStorage = (totalNumberOfBytes - freeBytesAvailable) / 1073741824.0;
            FreeStorage = totalNumberOfFreeBytes / 1073741824.0;

            UsedStoragePercent = (UsedStorage / TotalStorage) * 100.0;
        }
    }
}
