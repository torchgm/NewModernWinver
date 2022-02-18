using Microsoft.Toolkit.Uwp.Helpers;
using Microsoft.Toolkit.Uwp.UI.Helpers;
using System;
using System.Threading.Tasks;
using Windows.ApplicationModel.Core;
using Windows.System;
using Windows.UI;
using Windows.UI.ViewManagement;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
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
        private readonly int build;

        public MainPage()
        {
            build = SystemInformation.Instance.OperatingSystemVersion.Build;

            InitializeComponent();
            this.NavigationCacheMode = NavigationCacheMode.Required;

            ApplicationView appView = ApplicationView.GetForCurrentView();

            gvFrame1.Navigate(typeof(Views.AboutPage));
            gvFrame2.Navigate(typeof(Views.SystemPage));
            gvFrame3.Navigate(typeof(Views.ThemePage));
            gvFrame4.Navigate(typeof(Views.LinksPage));

            if (build > 21950)
            {
                LogoWin10.Visibility = Visibility.Collapsed;
                LogoWin11.Visibility = Visibility.Visible;
            }
            else
            {
                LogoWin10.Visibility = Visibility.Visible;
                LogoWin11.Visibility = Visibility.Collapsed;
            }

            CoreApplication.GetCurrentView().TitleBar.ExtendViewIntoTitleBar = true;

            appView.TitleBar.BackgroundColor = Colors.Transparent;
            appView.TitleBar.ButtonBackgroundColor = Colors.Transparent;
            appView.TitleBar.InactiveBackgroundColor = Colors.Transparent;
            appView.TitleBar.ButtonInactiveBackgroundColor = Colors.Transparent;
        }

        #region NavigationView event handlers
        private void nvTopLevelNav_Loaded(object sender, RoutedEventArgs e)
        {
            nvTopLevelNav.SelectedItem = nvTopLevelNav.MenuItems[0];
            contentFrame.Navigate(typeof(Views.AboutPage));
        }

        private async void nvTopLevelNav_ItemInvoked(Microsoft.UI.Xaml.Controls.NavigationView sender, Microsoft.UI.Xaml.Controls.NavigationViewItemInvokedEventArgs args)
        {
            if (args.IsSettingsInvoked)
            {
                await Launcher.LaunchUriAsync(new Uri("ms-settings:"));
                await ExitAppAsync();
            }
            else
            {
                if (args.InvokedItem is TextBlock ItemContent)
                {
                    switch (ItemContent.Tag)
                    {
                        case "Nav_About":
                            contentFrame.Navigate(typeof(Views.AboutPage), null,
                                args.RecommendedNavigationTransitionInfo);
                            break;

                        case "Nav_System":
                            contentFrame.Navigate(typeof(Views.SystemPage), null,
                                args.RecommendedNavigationTransitionInfo);
                            break;

                        case "Nav_Theme":
                            contentFrame.Navigate(typeof(Views.ThemePage), null,
                                args.RecommendedNavigationTransitionInfo);
                            break;

                        case "Nav_Links":
                            contentFrame.Navigate(typeof(Views.LinksPage), null,
                                args.RecommendedNavigationTransitionInfo);
                            break;
                    }
                }
            }
        }
        #endregion

        private async void okButton_Click(object sender, RoutedEventArgs e)
        {
            await ExitAppAsync();
        }

        private async Task ExitAppAsync()
        {
            // Exit the app gracefully if possible
            bool result = await ApplicationView.GetForCurrentView().TryConsolidateAsync();
            if (!result)
            {
                Application.Current.Exit();
            }
        }
    }
}
