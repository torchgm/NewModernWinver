using NewModernWinver.Interop;
using NewModernWinver.ViewModels;
using RegistryRT;
using System;
using System.ComponentModel;
using System.Text;
using System.Threading.Tasks;
using Windows.Storage;
using Windows.UI.Xaml.Controls;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

namespace NewModernWinver.Views
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class SystemPage : Page
    {
        private PerformanceInfoViewModel ViewModel => App.PerformanceViewModel;

        public SystemPage()
        {
            this.InitializeComponent();

            // Setup fields that don't get updated
            ulong freeBytesAvailable;
            ulong totalNumberOfBytes;
            ulong totalNumberOfFreeBytes;

            // You can only specify a folder path that this app can access, but you can
            // get full disk information from any folder path.
            IStorageFolder appFolder = ApplicationData.Current.LocalFolder;
            Imports.GetDiskFreeSpaceEx(appFolder.Path, out freeBytesAvailable, out totalNumberOfBytes, out totalNumberOfFreeBytes);
            valueTotalStorage.Text = $"{totalNumberOfBytes / 1073741824} GB";
            valueStorage.Text = $"{(totalNumberOfBytes - freeBytesAvailable) / 1073741824} GB used";
            valueFreeStorage.Text = $"{freeBytesAvailable / 1073741824} GB free";
            progressStorage.Value = Convert.ToDouble((decimal)freeBytesAvailable / (decimal)totalNumberOfBytes) * 100;
        }
    }
}
