using System;
using System.Text;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Threading.Tasks;
using System.ComponentModel;
using System.Diagnostics;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Core;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using RegistryRT;
using Windows.Storage;
using System.Runtime.InteropServices;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

namespace NewModernWinver.Views
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class SystemPage : Page
    {
        public SystemPage()
        {
            // RAM Background Worker
            BackgroundWorker bwRAM = new BackgroundWorker();
            bwRAM.WorkerReportsProgress = true;
            bwRAM.DoWork += BwRam_DoWork;
            bwRAM.ProgressChanged += BwRam_ProgressChanged;
            bwRAM.RunWorkerAsync();

            // CPU Background Worker
            BackgroundWorker bwCPU = new BackgroundWorker();
            bwCPU.WorkerReportsProgress = true;
            bwCPU.DoWork += BwCpu_DoWork;
            bwCPU.ProgressChanged += BwCpu_ProgressChanged;
            bwCPU.RunWorkerAsync();

            // Registry
            Registry reg = new Registry();
            reg.InitNTDLLEntryPoints();
            byte[] data;
            uint RegType;
            reg.QueryValue(RegistryHive.HKEY_LOCAL_MACHINE, @"HARDWARE\DESCRIPTION\System\CentralProcessor\0", "ProcessorNameString", out RegType, out data);
            string cpuName = Encoding.Unicode.GetString(data).Replace("\0", "").TrimEnd();
            reg.QueryValue(RegistryHive.HKEY_LOCAL_MACHINE, @"HARDWARE\DESCRIPTION\System\CentralProcessor\0", "~MHz", out RegType, out data);
            int cpuClock = BitConverter.ToInt32(data, 0);

            // UI
            this.InitializeComponent();
            PerformanceInfo.GeneralStatistics currentStats = PerformanceInfo.getGeneralStatistics();
            
            PerformanceInfo.GetNativeSystemInfo(out PerformanceInfo.SYSTEM_INFO sysInfo);
            valueArch.Text = ((PerformanceInfo.Arch)sysInfo.CpuInfo.ProcessorArchitecture).ToString();
            
            
            valueRAM.Text = Math.Round(currentStats.memoryTotal / 1024.0).ToString() + " GB";
            valueCPU.Text = cpuName;
            valueSystemName.Text = System.Net.Dns.GetHostName();
            valueClockSpeed.Text = cpuClock + " MHz";
            labelMaxCPU.Text = CpuUtil.ProcessorCount + " threads";

            ulong freeBytesAvailable;
            ulong totalNumberOfBytes;
            ulong totalNumberOfFreeBytes;

            // You can only specify a folder path that this app can access, but you can
            // get full disk information from any folder path.
            IStorageFolder appFolder = ApplicationData.Current.LocalFolder;
            GetDiskFreeSpaceEx(appFolder.Path, out freeBytesAvailable, out totalNumberOfBytes, out totalNumberOfFreeBytes);
            valueTotalStorage.Text = $"{totalNumberOfBytes / 1073741824} GB";
            valueStorage.Text = $"{(totalNumberOfBytes - freeBytesAvailable) / 1073741824} GB used";
            valueFreeStorage.Text = $"{freeBytesAvailable / 1073741824} GB free";
            progressStorage.Value = Convert.ToDouble((decimal)freeBytesAvailable / (decimal)totalNumberOfBytes) * 100;
        }

        // CPU Background Worker
        private void BwCpu_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            progressCPU.Value = e.ProgressPercentage;
            valueZeroCPU.Text = e.ProgressPercentage + "%";
            
        }

        private void BwCpu_DoWork(object sender, DoWorkEventArgs e)
        {
            BackgroundWorker bw = sender as BackgroundWorker;
            while (true)
            {
                bool visible = true;

                if (visible)
                {
                    int val = 0;
                    try
                    {
                        val = Convert.ToInt32(CpuUtil.GetPercentage());

                    }
                    catch (NullReferenceException)
                    {
                        
                    }
                    bw.ReportProgress(val);
                }
                System.Threading.Thread.Sleep(2000);
            }
        }

        // RAM Background Worker
        private void BwRam_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            progressRAM.Value = e.ProgressPercentage;
            PerformanceInfo.GeneralStatistics currentStats = PerformanceInfo.getGeneralStatistics();
            valueZeroRAM.Text = (currentStats.memoryInUse /1024).ToString() + " GB used";
            valueMaxRAM.Text = ((currentStats.memoryTotal - currentStats.memoryInUse) / 1024).ToString() + " GB free";
        }

        private void BwRam_DoWork(object sender, DoWorkEventArgs e)
        {
            BackgroundWorker bw = sender as BackgroundWorker;
            while (true)
            {
                PerformanceInfo.GeneralStatistics currentStats = PerformanceInfo.getGeneralStatistics();
                ulong usedMem = currentStats.memoryInUse;
                ulong totalMem = currentStats.memoryTotal;
                try
                {
                    bw.ReportProgress((int)Math.Round((decimal)usedMem / totalMem * 100));
                }
                catch (DivideByZeroException)
                {
                    bw.ReportProgress(0);
                }
                System.Threading.Thread.Sleep(2000);
            }
        }

        [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Auto)]
        [return: MarshalAs(UnmanagedType.Bool)]
        static extern bool GetDiskFreeSpaceEx(string lpDirectoryName, out ulong lpFreeBytesAvailable, out ulong lpTotalNumberOfBytes, out ulong lpTotalNumberOfFreeBytes);
    }
}
