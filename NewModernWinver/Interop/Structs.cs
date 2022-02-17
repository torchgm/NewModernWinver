using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace NewModernWinver.Interop
{
    [StructLayout(LayoutKind.Explicit)]
    public struct SYSTEM_INFO_UNION
    {
        [FieldOffset(0)]
        public UInt32 OemId;
        [FieldOffset(0)]
        public UInt16 ProcessorArchitecture;
        [FieldOffset(2)]
        public UInt16 Reserved;
    }

    public struct SYSTEM_INFO
    {
        public SYSTEM_INFO_UNION CpuInfo;
        public UInt32 PageSize;
        public UInt32 MinimumApplicationAddress;
        public UInt32 MaximumApplicationAddress;
        public UInt32 ActiveProcessorMask;
        public UInt32 NumberOfProcessors;
        public UInt32 ProcessorType;
        public UInt32 AllocationGranularity;
        public UInt16 ProcessorLevel;
        public UInt16 ProcessorRevision;
    }
}
