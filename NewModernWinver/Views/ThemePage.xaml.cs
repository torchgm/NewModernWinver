using NewModernWinver.ViewModels;
using System;
using System.Threading.Tasks;
using Windows.ApplicationModel.DataTransfer;
using Windows.Storage;
using Windows.Storage.Streams;
using Windows.System;
using Windows.System.UserProfile;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Media.Imaging;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

namespace NewModernWinver.Views
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class ThemePage : Page
    {
        private ThemeViewModel ViewModel => App.ThemeViewModel;

        public ThemePage()
        {
            InitializeComponent();
            this.NavigationCacheMode = NavigationCacheMode.Enabled;
        }

        private void CopyDeskWall_Click(object sender, RoutedEventArgs e)
        {
            var dataPackage = new DataPackage();
            dataPackage.SetBitmap(RandomAccessStreamReference.
                CreateFromFile(ViewModel.DeskWallFile));
            Clipboard.SetContent(dataPackage);
        }

        private void CopyLockWall_Click(object sender, RoutedEventArgs e)
        {
            var dataPackage = new DataPackage();
            dataPackage.SetBitmap(RandomAccessStreamReference.CreateFromStream(LockScreen.GetImageStream()));
            Clipboard.SetContent(dataPackage);
        }

        private async void PersonaliseDeskWall_Click(object sender, RoutedEventArgs e)
        {
            await Launcher.LaunchUriAsync(new Uri("ms-settings:personalization-background"));
        }

        private async void PersonaliseLockWall_Click(object sender, RoutedEventArgs e)
        {
            await Launcher.LaunchUriAsync(new Uri("ms-settings:lockscreen"));
        }

        private void CopyColor_Click(object sender, RoutedEventArgs e)
        {
            var dataPackage = new DataPackage();
            var uiSettings = new Windows.UI.ViewManagement.UISettings();
            var rgb = uiSettings.GetColorValue(Windows.UI.ViewManagement.UIColorType.Accent);
            dataPackage.SetText("#" + $"{rgb.R:X2}{rgb.G:X2}{rgb.B:X2}");
            Clipboard.SetContent(dataPackage);
        }

        private async void UpdatePrimaryAccent_Click(object sender, RoutedEventArgs e)
        {
            await Launcher.LaunchUriAsync(new Uri("ms-settings:colors"));
        }

        private void WarningButton_Click(object sender, RoutedEventArgs e)
        {
            WallTip.IsOpen = true;
        }

        private async void GetPermission_Click(Microsoft.UI.Xaml.Controls.TeachingTip sender, object args)
        {
            await Launcher.LaunchUriAsync(new Uri("ms-settings:privacy-broadfilesystemaccess"));
        }

        private async void PermissionInfo_Click(Microsoft.UI.Xaml.Controls.TeachingTip sender, object args)
        {
            await Launcher.LaunchUriAsync(new Uri("https://torch.is/typing/mwv/whyfiles.html"));
        }
    }
}
