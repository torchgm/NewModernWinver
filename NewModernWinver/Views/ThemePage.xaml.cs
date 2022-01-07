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

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

namespace NewModernWinver.Views
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class ThemePage : Page
    {
        public string wallpaperPath = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData).ToString() + @"\Microsoft\Windows\Themes\TranscodedWallpaper.jpg";
        public ThemePage()
        {
            this.InitializeComponent();
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
            StorageFile file = await folder.GetFileAsync("TranscodedWallpaper");
            using (var stream = await file.OpenAsync(FileAccessMode.Read))
            {
                BitmapImage bitmap = new BitmapImage();
                bitmap.SetSource(stream);
                valueWallpaper.ImageSource = bitmap;
            }
        }
    }
    
}
