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

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

namespace NewModernWinver.Views
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class ThemePage : Page
    {
        private readonly static DependencyProperty DeskWallVisibleProperty =
            DependencyProperty.Register(nameof(DeskWallVisible), typeof(bool),
                typeof(ThemePage), new PropertyMetadata(true));

        private readonly static DependencyProperty DeskWallProperty =
            DependencyProperty.Register(nameof(DeskWall), typeof(BitmapImage),
                typeof(ThemePage), new PropertyMetadata(new BitmapImage()));

        private readonly static DependencyProperty LockWallProperty =
            DependencyProperty.Register(nameof(LockWall), typeof(BitmapImage),
                typeof(ThemePage), new PropertyMetadata(new BitmapImage()));

        private bool DeskWallVisible
        {
            get => (bool)GetValue(DeskWallVisibleProperty);
            set => SetValue(DeskWallVisibleProperty, value);
        }

        private BitmapImage DeskWall
        {
            get => (BitmapImage)GetValue(DeskWallProperty);
            set => SetValue(DeskWallProperty, value);
        }

        private BitmapImage LockWall
        {
            get => (BitmapImage)GetValue(LockWallProperty);
            set => SetValue(LockWallProperty, value);
        }

        private readonly static string WallFolder =
            Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData).
            ToString() + @"\Microsoft\Windows\Themes\";

        private static StorageFile DeskWallFile;
        private static bool WallsSet = false;

        public ThemePage()
        {
            InitializeComponent();

            LockWall.DecodePixelHeight = 104;
            LockWall.DecodePixelWidth = 184;

            DeskWall.DecodePixelHeight = 104;
            DeskWall.DecodePixelWidth = 184;

            Loaded += async (s, e) =>
            {
                if (!WallsSet)
                {
                    WallsSet = true;
                    await LoadWallpaperAsync();
                }
            };
        }

        private async Task LoadWallpaperAsync()
        {
            bool canAccessWallFolder = System.IO.Directory.Exists(WallFolder);
            if (canAccessWallFolder)
            {
                try
                {
                    StorageFolder folder = await StorageFolder.GetFolderFromPathAsync(WallFolder);
                    DeskWallFile = await folder.GetFileAsync("TranscodedWallpaper");

                    using (var stream = await DeskWallFile.OpenAsync(FileAccessMode.Read))
                    {
                        await DeskWall.SetSourceAsync(stream);
                    }
                }
                catch (Exception)
                {
                    DeskWallVisible = false;
                }
            }
            else
            {
                DeskWallVisible = false;
            }

            await LockWall.SetSourceAsync(LockScreen.GetImageStream());
        }

        private void CopyDeskWall_Click(object sender, RoutedEventArgs e)
        {
            var dataPackage = new DataPackage();
            dataPackage.SetBitmap(RandomAccessStreamReference.CreateFromFile(DeskWallFile));
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

        private async void GetPermission_Click(object sender, RoutedEventArgs e)
        {
            await Launcher.LaunchUriAsync(new Uri("ms-settings:privacy-broadfilesystemaccess"));
        }

        private async void PermissionInfo_Click(object sender, RoutedEventArgs e)
        {
            await Launcher.LaunchUriAsync(new Uri("https://torch.is/typing/mwv/whyfiles.html"));
        }
    }

}
