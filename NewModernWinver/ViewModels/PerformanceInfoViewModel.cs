using NewModernWinver.Interop;
using RegistryRT;
using System;
using System.Net;
using System.Text;

namespace NewModernWinver.ViewModels
{
    public class PerformanceInfoViewModel : ViewModel
    {
        #region Interop
        public static SYSTEM_INFO SysInfo = new SYSTEM_INFO();
        private readonly MEMORYSTATUSEX mem = new MEMORYSTATUSEX();
        #endregion

        #region Private
        private string _processorName;
        private Arch _arch;
        private int _clock;
        private ulong _total;
        private double _used;
        private double _free;

        private Arch Arch
        {
            get => _arch;
            set
            {
                _arch = value;
                OnPropertyChanged(nameof(ProcessorArch));
            }
        }

        private int Clock
        {
            get => _clock;
            set
            {
                _clock = value;
                OnPropertyChanged(nameof(ClockSpeed));
            }
        }

        private ulong Total
        {
            get => _total;
            set
            {
                _total = value;
                OnPropertyChanged(nameof(TotalMemory));
            }
        }

        private double Used
        {
            get => _used;
            set
            {
                _used = Math.Round(value, 3, MidpointRounding.AwayFromZero);
                OnPropertyChanged(nameof(UsedMemory));
                OnPropertyChanged(nameof(UsedMemoryPercent));
            }
        }

        private double Free
        {
            get => _free;
            set
            {
                _free = Math.Round(value, 3, MidpointRounding.AwayFromZero);
                OnPropertyChanged(nameof(FreeMemory));
            }
        }
        #endregion

        public PerformanceInfoViewModel()
        {
            // No need to get this more than once
            Imports.GlobalMemoryStatusEx(mem);
            Total = mem.ullTotalPhys / 1048576;

            SetCpuInfo();
            Update();
        }

        public string SystemName => Dns.GetHostName();

        #region Processor
        public string ProcessorName
        {
            get => _processorName;
            set => Set(ref _processorName, value);
        }

        public string ProcessorArch => Arch.ToString();
        public string ClockSpeed => Clock.ToString() + "MHz";
        public string Threads => CpuUtil.ProcessorCount + " threads";

        public int CpuUsage
        {
            get
            {
                int val = 0;
                try
                {
                    val = Convert.ToInt32(CpuUtil.GetPercentage());
                }
                catch (NullReferenceException) { }

                return val;
            }
        }

        public string CpuUsagePercent => CpuUsage.ToString() + "%";
        #endregion

        #region Memory
        public string TotalMemory => Math.Round(_total / 1024.0).ToString() + "GB";
        public string UsedMemory => Used.ToString() + "GB used";
        public string FreeMemory => Free.ToString() + "GB free";

        public int UsedMemoryPercent
        {
            get
            {
                int val = 0;
                try
                {
                    val = (int)Math.Round((decimal)Used / Total * 100);
                }
                catch (DivideByZeroException) { }

                return val;
            }
        }
        #endregion

        public void Update()
        {
            Imports.GlobalMemoryStatusEx(mem);

            Used = (mem.ullTotalPhys - mem.ullAvailPhys) / 1048576 / 1024.0;
            Free = (Total - Used) / 1024.0;

            OnPropertyChanged(nameof(CpuUsage));
        }

        private void SetCpuInfo()
        {
            Imports.GetNativeSystemInfo(out SYSTEM_INFO sysInfo);
            Arch = (Arch)sysInfo.CpuInfo.ProcessorArchitecture;

            Registry reg = new Registry();
            reg.InitNTDLLEntryPoints();

            reg.QueryValue(RegistryHive.HKEY_LOCAL_MACHINE, @"HARDWARE\DESCRIPTION\System\CentralProcessor\0", "ProcessorNameString", out uint RegType, out byte[] data);
            ProcessorName = Encoding.Unicode.GetString(data).Replace("\0", "").TrimEnd();

            reg.QueryValue(RegistryHive.HKEY_LOCAL_MACHINE, @"HARDWARE\DESCRIPTION\System\CentralProcessor\0", "~MHz", out RegType, out data);
            Clock = BitConverter.ToInt32(data, 0);
        }
    }
}
