using Microsoft.Toolkit.Uwp.UI.Helpers;
using Windows.ApplicationModel.Core;
using Windows.Foundation;
using Windows.UI;
using Windows.UI.ViewManagement;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using System.Runtime.InteropServices;
using Microsoft.Toolkit.Uwp.Helpers;
using NewModernWinver.Views;
using Windows.UI.Xaml.Navigation;


// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace NewModernWinver
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    /// 

    public sealed partial class MainPage : Page
    {
        int build;

        public MainPage()
        {
            build = SystemInformation.Instance.OperatingSystemVersion.Build;
            var Listener = new ThemeListener();
            Listener.ThemeChanged += Listener_ThemeChanged;

            InitializeComponent();

            gvFrame1.Navigate(typeof(Views.AboutPage));
            gvFrame2.Navigate(typeof(Views.SystemPage));
            gvFrame3.Navigate(typeof(Views.ThemePage));
            gvFrame4.Navigate(typeof(Views.LinksPage));
            if (ActualTheme == ElementTheme.Light)
            {
                if (build > 21950)
                {
                    LogoWin11Dark.Visibility = Visibility.Collapsed;
                    LogoWin11Light.Visibility = Visibility.Visible;
                }
                else
                {
                    LogoWin10Dark.Visibility = Visibility.Collapsed;
                    LogoWin10Light.Visibility = Visibility.Visible;
                }

            }
            else
            {
                if (build > 21950)
                {
                    LogoWin11Light.Visibility = Visibility.Collapsed;
                    LogoWin11Dark.Visibility = Visibility.Visible;
                }
                else
                {
                    LogoWin10Light.Visibility = Visibility.Collapsed;
                    LogoWin10Dark.Visibility = Visibility.Visible;
                }

            }

            ApplicationView appView = ApplicationView.GetForCurrentView();
            CoreApplication.GetCurrentView().TitleBar.ExtendViewIntoTitleBar = true;

            appView.TitleBar.BackgroundColor = Colors.Transparent;
            appView.TitleBar.ButtonBackgroundColor = Colors.Transparent;
            appView.TitleBar.InactiveBackgroundColor = Colors.Transparent;
            appView.TitleBar.ButtonInactiveBackgroundColor = Colors.Transparent;
        }

        #region NavigationView event handlers
        private void Listener_ThemeChanged(ThemeListener sender)
        {
            var theme = sender.CurrentTheme;
            if (theme == ApplicationTheme.Light)
            {
                if (build > 21950)
                {
                    LogoWin11Dark.Visibility = Visibility.Collapsed;
                    LogoWin11Light.Visibility = Visibility.Visible;
                    LogoWin10Dark.Visibility = Visibility.Collapsed;
                    LogoWin10Light.Visibility = Visibility.Collapsed;

                }
                else
                {
                    LogoWin10Dark.Visibility = Visibility.Collapsed;
                    LogoWin10Light.Visibility = Visibility.Visible;
                    LogoWin11Dark.Visibility = Visibility.Collapsed;
                    LogoWin11Light.Visibility = Visibility.Collapsed;
                }
            }
            else
            {
                if (build > 21950)
                {
                    LogoWin11Light.Visibility = Visibility.Collapsed;
                    LogoWin11Dark.Visibility = Visibility.Visible;
                    LogoWin10Light.Visibility = Visibility.Collapsed;
                    LogoWin10Dark.Visibility = Visibility.Collapsed;
                }
                else
                {
                    LogoWin10Light.Visibility = Visibility.Collapsed;
                    LogoWin10Dark.Visibility = Visibility.Visible;
                    LogoWin11Light.Visibility = Visibility.Collapsed;
                    LogoWin11Dark.Visibility = Visibility.Collapsed;
                }
            }
        }

        private void nvTopLevelNav_ItemInvoked(Microsoft.UI.Xaml.Controls.NavigationView sender, Microsoft.UI.Xaml.Controls.NavigationViewItemInvokedEventArgs args)
        {
            if (args.IsSettingsInvoked)
            {
                // Unused atm because NavigationView hates me
                // Process.Start("ms-settings:");
                // Close();
            }
            else
            {
                if (args.InvokedItem is TextBlock ItemContent)
                {
                    switch (ItemContent.Tag)
                    {
                        case "Nav_About":
                            contentFrame.Navigate(typeof(AboutPage));
                            break;

                        case "Nav_System":
                            contentFrame.Navigate(typeof(SystemPage));
                            break;

                        case "Nav_Theme":
                            contentFrame.Navigate(typeof(ThemePage));
                            break;

                        case "Nav_Links":
                            contentFrame.Navigate(typeof(LinksPage));
                            break;
                    }
                }
            }
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            if (e.Parameter is string param)
            {
                switch (param)
                {
                    case "mwv:system":
                        contentFrame.Navigate(typeof(SystemPage));
                        nvTopLevelNav.SelectedItem = nvTopLevelNav.MenuItems[1];
                        break;

                    case "mwv:theme":
                        contentFrame.Navigate(typeof(ThemePage));
                        nvTopLevelNav.SelectedItem = nvTopLevelNav.MenuItems[2];
                        break;

                    case "mwv:links":
                        contentFrame.Navigate(typeof(LinksPage));
                        nvTopLevelNav.SelectedItem = nvTopLevelNav.MenuItems[3];
                        break;

                    default:
                        contentFrame.Navigate(typeof(AboutPage));
                        nvTopLevelNav.SelectedItem = nvTopLevelNav.MenuItems[0];
                        break;
                }
            }
        }
        #endregion

        private void okButton_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Exit();
        }

        [DllImport("kernel32.dll", SetLastError = false)]
        static extern bool GetProductInfo(int dwOSMajorVersion, int dwOSMinorVersion, int dwSpMajorVersion, int dwSpMinorVersion, out int pdwReturnedProductType);
    }
}
