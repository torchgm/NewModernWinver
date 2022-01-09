using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Media.Imaging;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using System.Diagnostics;
using Windows.Storage;
using Windows.Storage.Streams;
using Windows.ApplicationModel.DataTransfer;
using Windows.System;
using Windows.System.UserProfile;
using Windows.ApplicationModel;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

namespace NewModernWinver.Views
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class ThemePage : Page
    {
        public string wallpaperPath = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData).ToString() + @"\Microsoft\Windows\Themes\TranscodedWallpaper.jpg";
        public StorageFile file;

        public ThemePage()
        {
            InitializeComponent();
            try
            {
                LoadWallpaper();
            }
            catch (Exception)
            {

            }
        }

        public async void LoadWallpaper()
        {
            StorageFolder folder = await StorageFolder.GetFolderFromPathAsync(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData).ToString() + @"\Microsoft\Windows\Themes\");
            file = await folder.GetFileAsync("TranscodedWallpaper");
            using (var stream = await file.OpenAsync(FileAccessMode.Read))
            {
                BitmapImage desktop = new BitmapImage();
                BitmapImage lockscreen = new BitmapImage();

                desktop.SetSource(stream);
                valueWallpaper.ImageSource = desktop;
                lockscreen.SetSource(LockScreen.GetImageStream());
                valueLockScreen.ImageSource = lockscreen;
            }
        }

        private void buttonCopyWallpaper_Click(object sender, RoutedEventArgs e)
        {
            var dataPackage = new DataPackage();
            dataPackage.SetBitmap(RandomAccessStreamReference.CreateFromFile(file));
            Clipboard.SetContent(dataPackage);
        }

        private async void buttonPersonalisationBackground_Click(object sender, RoutedEventArgs e)
        {
            await Launcher.LaunchUriAsync(new Uri("ms-settings:personalization-background"));
        }

        private void buttonCopyLockScreen_Click(object sender, RoutedEventArgs e)
        {
            var dataPackage = new DataPackage();
            dataPackage.SetBitmap(RandomAccessStreamReference.CreateFromStream(LockScreen.GetImageStream()));
            Clipboard.SetContent(dataPackage);
        }

        private async void buttonPersonalisationLockScreen_Click(object sender, RoutedEventArgs e)
        {
            await Launcher.LaunchUriAsync(new Uri("ms-settings:personalization-lockscreen"));
        }

        private void buttonCopyColour_Click(object sender, RoutedEventArgs e)
        {
            var dataPackage = new DataPackage();
            var uiSettings = new Windows.UI.ViewManagement.UISettings();
            var rgb = uiSettings.GetColorValue(Windows.UI.ViewManagement.UIColorType.Accent);
            dataPackage.SetText("#" + $"{rgb.R:X2}{rgb.G:X2}{rgb.B:X2}");
            Clipboard.SetContent(dataPackage);
        }

        private async void buttonUpdatePrimaryAccent_Click(object sender, RoutedEventArgs e)
        {
            await Launcher.LaunchUriAsync(new Uri("ms-settings:colors"));
        }
    }
    
}
