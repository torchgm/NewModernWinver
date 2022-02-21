using NewModernWinver.Misc;
using System;
using System.Threading.Tasks;
using Windows.Storage;
using Windows.System.UserProfile;
using Windows.UI.Xaml.Media.Imaging;

namespace NewModernWinver.ViewModels
{
    public class ThemeViewModel : ViewModel
    {
        #region Private fields
        private readonly static string WallFolder =
            Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData).
            ToString() + @"\Microsoft\Windows\Themes\";

        private bool _wallsLoaded = false;
        private bool _deskWallVisible = true;

        private SoftwareBitmapSource _deskWall;
        private SoftwareBitmapSource _lockWall;
        #endregion

        public StorageFile DeskWallFile { get; set; }

        public bool DeskWallVisible
        {
            get => _deskWallVisible;
            set => Set(ref _deskWallVisible, value);
        }

        public SoftwareBitmapSource DeskWall
        {
            get => _deskWall;
            set => Set(ref _deskWall, value);
        }

        public SoftwareBitmapSource LockWall
        {
            get => _lockWall;
            set => Set(ref _lockWall, value);
        }

        public async Task LoadWallpapersAsync()
        {
            if (_wallsLoaded)
            {
                return;
            }

            _wallsLoaded = true;
            using (var stream = LockScreen.GetImageStream())
            {
                var bmp = await stream.GetBitmapAsync(184, 104);
                LockWall = await bmp.GetSourceAsync();
            }

            var canAccess = System.IO.Directory.Exists(WallFolder);
            if (canAccess)
            {
                try
                {
                    DeskWallFile = await StorageFile.
                        GetFileFromPathAsync(WallFolder + "TranscodedWallpaper");

                    var bmp = await DeskWallFile.GetBitmapAsync(184, 104);
                    DeskWall = await bmp.GetSourceAsync();
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
        }
    }
}
