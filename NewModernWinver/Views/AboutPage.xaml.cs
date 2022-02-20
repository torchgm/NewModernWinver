using Microsoft.Toolkit.Uwp.Helpers;
using NewModernWinver.Interop;
using NewModernWinver.Misc;
using RegistryRT;
using System;
using System.Security.Principal;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

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
            Registry reg;
            try
            {
                reg = new Registry();

            }
            catch (Exception)
            {
                throw;
            }

            InitializeComponent();
            NavigationCacheMode = NavigationCacheMode.Enabled;

            labelCopyright.Text = "©️ " + DateTime.Now.Year + " Microsoft Corporation. All rights reserved";
            Imports.GetProductInfo(6, 3, 0, 0, out int osEdition);

            if (ListsAndStuff.EditionDict.ContainsKey(osEdition))
            {
                string edition = ListsAndStuff.EditionDict[osEdition];
                if (build <= 21996)
                {
                    valueEdition.Text = edition;
                }
                else
                {
                    valueEdition.Text = edition.Replace("Windows 10", "Windows 11");
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
                valueUpdate.Text = "Dev";
            }
        }
    }
}
