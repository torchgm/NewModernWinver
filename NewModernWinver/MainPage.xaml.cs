using Microsoft.Toolkit.Uwp.Helpers;
using NewModernWinver.Views;
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
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            InitializeComponent();
            this.NavigationCacheMode = NavigationCacheMode.Required;

            this.Loaded += OnLoaded;
            SetupTitleBar();
        }

        private async void OnLoaded(object sender, RoutedEventArgs e)
        {
            if (SystemInformation.Instance.OperatingSystemVersion.Build > 21950)
            {
                LogoWin10.Visibility = Visibility.Collapsed;
                LogoWin11.Visibility = Visibility.Visible;
            }
            else
            {
                LogoWin10.Visibility = Visibility.Visible;
                LogoWin11.Visibility = Visibility.Collapsed;
            }

            gvFrame1.Navigate(typeof(AboutPage));
            gvFrame2.Navigate(typeof(SystemPage));
            gvFrame3.Navigate(typeof(ThemePage));
            gvFrame4.Navigate(typeof(LinksPage));

            await App.ThemeViewModel.LoadWallpapersAsync();
        }

        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            if (e.Parameter is string param)
            {
                switch (param)
                {
                    case "mwv:system":
                        contentFrame.Navigate(typeof(SystemPage));
                        topLevelNav.SelectedItem = topLevelNav.MenuItems[1];
                        break;

                    case "mwv:theme":
                        contentFrame.Navigate(typeof(ThemePage));
                        topLevelNav.SelectedItem = topLevelNav.MenuItems[2];
                        break;

                    case "mwv:links":
                        contentFrame.Navigate(typeof(LinksPage));
                        topLevelNav.SelectedItem = topLevelNav.MenuItems[3];
                        break;

                    default:
                        contentFrame.Navigate(typeof(AboutPage));
                        topLevelNav.SelectedItem = topLevelNav.MenuItems[0];
                        break;
                }
            }

            base.OnNavigatedTo(e);
        }

        private async void TopLevelNav_ItemInvoked(Microsoft.UI.Xaml.Controls.NavigationView sender, Microsoft.UI.Xaml.Controls.NavigationViewItemInvokedEventArgs args)
        {
            if (args.IsSettingsInvoked)
            {
                await Launcher.LaunchUriAsync(new Uri("ms-settings:"));
                await ExitAppAsync();
            }
            else
            {
                if (args.InvokedItem is TextBlock itemContent)
                {
                    switch (itemContent.Tag)
                    {
                        case "Nav_About":
                            contentFrame.Navigate(typeof(AboutPage), null,
                                args.RecommendedNavigationTransitionInfo);
                            break;

                        case "Nav_System":
                            contentFrame.Navigate(typeof(SystemPage), null,
                                args.RecommendedNavigationTransitionInfo);
                            break;

                        case "Nav_Theme":
                            contentFrame.Navigate(typeof(ThemePage), null,
                                args.RecommendedNavigationTransitionInfo);
                            break;

                        case "Nav_Links":
                            contentFrame.Navigate(typeof(LinksPage), null,
                                args.RecommendedNavigationTransitionInfo);
                            break;
                    }
                }
            }
        }

        private async void OkButton_Click(object sender, RoutedEventArgs e)
        {
            await ExitAppAsync();
        }

        private void SetupTitleBar()
        {
            CoreApplication.GetCurrentView().TitleBar.ExtendViewIntoTitleBar = true;
            ApplicationView appView = ApplicationView.GetForCurrentView();

            appView.TitleBar.BackgroundColor = Colors.Transparent;
            appView.TitleBar.ButtonBackgroundColor = Colors.Transparent;

            appView.TitleBar.InactiveBackgroundColor = Colors.Transparent;
            appView.TitleBar.ButtonInactiveBackgroundColor = Colors.Transparent;
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
