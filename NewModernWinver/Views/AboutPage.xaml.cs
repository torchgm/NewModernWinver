using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using System.Security.Principal;
using Windows.System.Profile;
using Windows.ApplicationModel;
using Windows.Security.ExchangeActiveSyncProvisioning;
using Microsoft.Toolkit.Uwp.Helpers;
using System.Runtime.InteropServices;
using RegistryRT;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

namespace NewModernWinver.Views
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class AboutPage : Page
    {
        int build = SystemInformation.Instance.OperatingSystemVersion.Build;
        int rev = SystemInformation.Instance.OperatingSystemVersion.Revision;

        public AboutPage()
        {
            Registry reg = new Registry();

            int osEdition = 0;
            InitializeComponent();
            GetProductInfo(6, 3, 0, 0, out osEdition);

            if (ListsAndStuff.EditionDict.ContainsKey(osEdition))
            {
                string Edition = ListsAndStuff.EditionDict[osEdition];
            if (build < 21996)
                {

                    valueEdition.Text = Edition;
                }
                else
                {
                    valueEdition.Text = Edition.Replace("Windows 10", "Windows 11");
                }
            }
            else
            {
                valueEdition.Text = "Unknown";
            }

            byte[] data = new byte[256];

            reg.InitNTDLLEntryPoints();

            reg.QueryValue(RegistryHive.HKEY_CURRENT_USER, @"Control Panel\Desktop\Colors", "Window", out RegistryType _, out _);


            int unixInstall = 0;
            try
            {
                reg.QueryValue(RegistryHive.HKEY_LOCAL_MACHINE, @"SOFTWARE\Microsoft\Windows NT\CurrentVersion", "InstallDate", out uint RegType, out data);
                unixInstall = BitConverter.ToInt32(data, 0);
            }
            catch (Exception)
            {
            }
            valueDate.Text = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc).AddSeconds(unixInstall).ToString();

            valueComputername.Text = System.Net.Dns.GetHostName();
            valueUsername.Text = WindowsIdentity.GetCurrent().Name.Replace(valueComputername.Text + "\\", "");

            valueBuild.Text = build + "." + rev;
            if (ListsAndStuff.BuildDict.ContainsKey(build))
            {
                valueUpdate.Text = ListsAndStuff.BuildDict[build];
            }
            else
            {
                valueUpdate.Text = "001";
            }
        }

        [DllImport("kernel32.dll", SetLastError = false)]
        static extern bool GetProductInfo(int dwOSMajorVersion, int dwOSMinorVersion, int dwSpMajorVersion, int dwSpMinorVersion, out int pdwReturnedProductType);
    }
}
