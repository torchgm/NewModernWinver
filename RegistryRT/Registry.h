/*
MIT License

Copyright (c) 2019 Gustave Monce - @gus33000 - gus33000.me

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once
#include <collection.h>
#include <windows.h>

namespace RegistryRT
{

	public enum class RegistryType
	{
		None = REG_NONE,
		String = REG_SZ,
		VariableString = REG_EXPAND_SZ,
		Binary = REG_BINARY,
		Integer = REG_DWORD,
		IntegerBigEndian = REG_DWORD_BIG_ENDIAN,
		SymbolicLink = REG_LINK,
		MultiString = REG_MULTI_SZ,
		ResourceList = REG_RESOURCE_LIST,
		HardwareResourceList = REG_FULL_RESOURCE_DESCRIPTOR,
		ResourceRequirement = REG_RESOURCE_REQUIREMENTS_LIST,
		Long = REG_QWORD
	};

	#undef HKEY_CLASSES_ROOT
	#undef HKEY_CURRENT_USER
	#undef HKEY_LOCAL_MACHINE
	#undef HKEY_USERS
	#undef HKEY_CURRENT_CONFIG
	#undef HKEY_CURRENT_USER_LOCAL_SETTINGS

	public enum class RegistryHive
	{
		HKEY_CLASSES_ROOT,
		HKEY_CURRENT_USER,
		HKEY_LOCAL_MACHINE,
		HKEY_USERS,
		HKEY_CURRENT_CONFIG,
		HKEY_CURRENT_USER_LOCAL_SETTINGS
	};


	typedef DWORD ULONG;
	typedef WORD  USHORT, *USHORT_PTR;
	typedef ULONG NTSTATUS, *PNTSTATUS;

	typedef ULONG ACCESS_MASK, *PACCESS_MASK;

	#define FILE_SUPERSEDE					0x00000000
	#define FILE_OPEN						0x00000001
	#define FILE_CREATE						0x00000002
	#define FILE_OPEN_IF					0x00000003
	#define FILE_OVERWRITE					0x00000004
	#define FILE_OVERWRITE_IF				0x00000005
	#define FILE_MAXIMUM_DISPOSITION		0x00000005

	#define ERROR_FUNCTION_FAILED			1627L

	#define FILE_DIRECTORY_FILE				0x00000001
	#define FILE_WRITE_THROUGH				0x00000002
	#define FILE_SEQUENTIAL_ONLY			0x00000004
	#define FILE_NO_INTERMEDIATE_BUFFERING	0x00000008

	#define FILE_SYNCHRONOUS_IO_ALERT		0x00000010
	#define FILE_SYNCHRONOUS_IO_NONALERT	0x00000020
	#define FILE_NON_DIRECTORY_FILE			0x00000040
	#define FILE_CREATE_TREE_CONNECTION		0x00000080

	#define FILE_COMPLETE_IF_OPLOCKED		0x00000100
	#define FILE_NO_EA_KNOWLEDGE			0x00000200
	#define FILE_OPEN_FOR_RECOVERY			0x00000400
	#define FILE_RANDOM_ACCESS				0x00000800

	#define FILE_DELETE_ON_CLOSE			0x00001000
	#define FILE_OPEN_BY_FILE_ID			0x00002000
	#define FILE_OPEN_FOR_BACKUP_INTENT		0x00004000
	#define FILE_NO_COMPRESSION				0x00008000

	#define FILE_RESERVE_OPFILTER			0x00100000
	#define FILE_OPEN_REPARSE_POINT			0x00200000
	#define FILE_OPEN_NO_RECALL				0x00400000
	#define FILE_OPEN_FOR_FREE_SPACE_QUERY	0x00800000

	#define FILE_COPY_STRUCTURED_STORAGE	0x00000041
	#define FILE_STRUCTURED_STORAGE			0x00000441

	#define FILE_VALID_OPTION_FLAGS			0x00ffffff
	#define FILE_VALID_PIPE_OPTION_FLAGS	0x00000032
	#define FILE_VALID_MAILSLOT_OPTION_FLAGS	0x00000032
	#define FILE_VALID_SET_FLAGS			0x00000036

	#define STATUS_SUCCESS				((NTSTATUS)0x00000000L) // ntsubauth
	#define STATUS_BUFFER_OVERFLOW		((NTSTATUS)0x80000005L)
	#define STATUS_INVALID_PARAMETER	((NTSTATUS)0xC000000DL)
	#define STATUS_ACCESS_DENIED		((NTSTATUS)0xC0000022L)
	#define STATUS_NO_MORE_ENTRIES		((NTSTATUS)0x8000001AL)
	#define STATUS_OBJECT_TYPE_MISMATCH ((NTSTATUS)0xC0000024L)

	#define NT_SUCCESS(Status) ((NTSTATUS)(Status) == STATUS_SUCCESS)
	#define HKU		HKEY_USERS
	#define HKLM	HKEY_LOCAL_MACHINE
	#define HKCU	HKEY_CURRENT_USER
	#define HKCC	HKEY_CURRENT_CONFIG
	#define HKCR	HKEY_CLASSES_ROOT

	typedef struct _OBJECT_BASIC_INFORMATION {
		ULONG Attributes;
		ACCESS_MASK GrantedAccess;
		ULONG HandleCount;
		ULONG PointerCount;
		ULONG PagedPoolUsage;
		ULONG NonPagedPoolUsage;
		ULONG Reserved[3];
		ULONG NameInformationLength;
		ULONG TypeInformationLength;
		ULONG SecurityDescriptorLength;
		LARGE_INTEGER CreateTime;
	} OBJECT_BASIC_INFORMATION, *POBJECT_BASIC_INFORMATION;

	typedef struct _UNICODE_STRING
	{
		USHORT Length;
		USHORT MaximumLength;
		PWSTR  Buffer;
	} UNICODE_STRING;
	typedef UNICODE_STRING *PUNICODE_STRING;

	// InitializeUnicodeStrings (WCHAR wstr, BOOL hidden, UNICODE_STRING* us);
	#define InitializeUnicodeStrings( wstr, hidden, us ) {                                \
		(us)->Buffer = (PWSTR)wstr;                                                              \
		(us)->Length = (USHORT)(wcslen((const wchar_t *)wstr) * sizeof(WCHAR)) + (sizeof(WCHAR) * hidden); \
		(us)->MaximumLength = (us)->Length+4;                                             \
	}

	typedef struct _STRING
	{
		USHORT Length;
		USHORT MaximumLength;
		//#ifdef MIDL_PASS
		//    [size_is(MaximumLength), length_is(Length) ]
		//#endif // MIDL_PASS
		PCHAR Buffer;
	} STRING;
	typedef STRING *PSTRING;
	typedef STRING OEM_STRING;
	typedef STRING *POEM_STRING;
	typedef STRING ANSI_STRING;
	typedef STRING *PANSI_STRING;
	
	typedef struct _KEY_BASIC_INFORMATION
	{
		LARGE_INTEGER LastWriteTime;// The last time the key or any of its values changed.
		ULONG TitleIndex;			// Device and intermediate drivers should ignore this member.
		ULONG NameLength;			// The size in bytes of the following name, including the zero-terminating character.
		WCHAR Name[1];				// A zero-terminated Unicode string naming the key.
	} KEY_BASIC_INFORMATION;
	typedef KEY_BASIC_INFORMATION *PKEY_BASIC_INFORMATION;

	typedef struct _KEY_FULL_INFORMATION
	{
		LARGE_INTEGER LastWriteTime;// The last time the key or any of its values changed.
		ULONG TitleIndex;			// Device and intermediate drivers should ignore this member.
		ULONG ClassOffset;			// The offset from the start of this structure to the Class member.
		ULONG ClassLength;			// The number of bytes in the Class name.
		ULONG SubKeys;				// The number of subkeys for the key.
		ULONG MaxNameLen;			// The maximum length of any name for a subkey.
		ULONG MaxClassLen;			// The maximum length for a Class name.
		ULONG Values;				// The number of value entries.
		ULONG MaxValueNameLen;		// The maximum length of any value entry name.
		ULONG MaxValueDataLen;		// The maximum length of any value entry data field.
		WCHAR Class[1];				// A zero-terminated Unicode string naming the class of the key.
	} KEY_FULL_INFORMATION;
	typedef KEY_FULL_INFORMATION *PKEY_FULL_INFORMATION;

	typedef struct _KEY_NODE_INFORMATION
	{
		LARGE_INTEGER LastWriteTime;// The last time the key or any of its values changed.
		ULONG TitleIndex;			// Device and intermediate drivers should ignore this member.
		ULONG ClassOffset;			// The offset from the start of this structure to the Class member.
		ULONG ClassLength;			// The number of bytes in the Class name.
		ULONG NameLength;			// The size in bytes of the following name, including the zero-terminating character.
		WCHAR Name[1];				// A zero-terminated Unicode string naming the key.
	} KEY_NODE_INFORMATION;
	typedef KEY_NODE_INFORMATION *PKEY_NODE_INFORMATION;

	// end_wdm
	typedef struct _KEY_NAME_INFORMATION
	{
		ULONG   NameLength;
		WCHAR   Name[1];            // Variable length string
	} KEY_NAME_INFORMATION, *PKEY_NAME_INFORMATION;
	typedef KEY_NAME_INFORMATION *PKEY_NAME_INFORMATION;

	// begin_wdm
	typedef enum _KEY_INFORMATION_CLASS
	{
		KeyBasicInformation,
		KeyNodeInformation,
		KeyFullInformation
		// end_wdm
		,
		KeyNameInformation
		// begin_wdm
	} KEY_INFORMATION_CLASS;

	typedef struct _KEY_WRITE_TIME_INFORMATION
	{
		LARGE_INTEGER LastWriteTime;
	} KEY_WRITE_TIME_INFORMATION;
	typedef KEY_WRITE_TIME_INFORMATION *PKEY_WRITE_TIME_INFORMATION;

	typedef enum _KEY_SET_INFORMATION_CLASS
	{
		KeyWriteTimeInformation
	} KEY_SET_INFORMATION_CLASS;

	typedef struct _KEY_VALUE_BASIC_INFORMATION
	{
		ULONG TitleIndex;	// Device and intermediate drivers should ignore this member.
		ULONG Type;			// The system-defined type for the registry value in the 
							// Data member (see the values above).
		ULONG NameLength;	// The size in bytes of the following value entry name, 
							// including the zero-terminating character.
		WCHAR Name[1];		// A zero-terminated Unicode string naming a value entry of 
							// the key.
	} KEY_VALUE_BASIC_INFORMATION;
	typedef KEY_VALUE_BASIC_INFORMATION *PKEY_VALUE_BASIC_INFORMATION;

	typedef struct _KEY_VALUE_FULL_INFORMATION
	{
		ULONG TitleIndex;	// Device and intermediate drivers should ignore this member.
		ULONG Type;			// The system-defined type for the registry value in the 
							// Data member (see the values above).
		ULONG DataOffset;	// The offset from the start of this structure to the data 
							// immediately following the Name string.
		ULONG DataLength;	// The number of bytes of registry information for the value 
							// entry identified by Name.
		ULONG NameLength;	// The size in bytes of the following value entry name, 
							// including the zero-terminating character.
		WCHAR Name[1];		// A zero-terminated Unicode string naming a value entry of 
							// the key.
							//	WCHAR Data[1];      // Variable size data not declared
	} KEY_VALUE_FULL_INFORMATION;
	typedef KEY_VALUE_FULL_INFORMATION *PKEY_VALUE_FULL_INFORMATION;

	typedef struct _KEY_VALUE_PARTIAL_INFORMATION
	{
		ULONG TitleIndex;	// Device and intermediate drivers should ignore this member.
		ULONG Type;			// The system-defined type for the registry value in the 
							// Data member (see the values above).
		ULONG DataLength;	// The size in bytes of the Data member.
		UCHAR Data[1];		// A value entry of the key.
	} KEY_VALUE_PARTIAL_INFORMATION;
	typedef KEY_VALUE_PARTIAL_INFORMATION *PKEY_VALUE_PARTIAL_INFORMATION;

	typedef struct _KEY_VALUE_ENTRY
	{
		PUNICODE_STRING ValueName;
		ULONG           DataLength;
		ULONG           DataOffset;
		ULONG           Type;
	} KEY_VALUE_ENTRY;
	typedef KEY_VALUE_ENTRY *PKEY_VALUE_ENTRY;

	typedef enum _KEY_VALUE_INFORMATION_CLASS
	{
		KeyValueBasicInformation,
		KeyValueFullInformation,
		KeyValuePartialInformation,
	} KEY_VALUE_INFORMATION_CLASS;

	typedef struct _KEY_MULTIPLE_VALUE_INFORMATION
	{
		PUNICODE_STRING	ValueName;
		ULONG			DataLength;
		ULONG			DataOffset;
		ULONG			Type;
	} KEY_MULTIPLE_VALUE_INFORMATION;
	typedef KEY_MULTIPLE_VALUE_INFORMATION *PKEY_MULTIPLE_VALUE_INFORMATION;

	typedef struct _IO_STATUS_BLOCK
	{
		union
		{
			NTSTATUS	Status;
			PVOID		Pointer;
		};
		ULONG_PTR	Information;
	} IO_STATUS_BLOCK;
	typedef IO_STATUS_BLOCK *PIO_STATUS_BLOCK;

	typedef void (NTAPI *PIO_APC_ROUTINE)
		(
			IN PVOID ApcContext,
			IN PIO_STATUS_BLOCK IoStatusBlock,
			IN ULONG Reserved
			);

	typedef struct _CLIENT_ID
	{
		HANDLE UniqueProcess;
		HANDLE UniqueThread;
	} CLIENT_ID;
	typedef CLIENT_ID *PCLIENT_ID;

	#define OBJ_INHERIT				0x00000002L
	#define OBJ_PERMANENT			0x00000010L
	#define OBJ_EXCLUSIVE			0x00000020L
	#define OBJ_CASE_INSENSITIVE	0x00000040
	#define OBJ_OPENIF				0x00000080L
	#define OBJ_KERNEL_HANDLE		0x00000200L
	#define OBJ_FORCE_ACCESS_CHECK	0x00000400L
	#define OBJ_VALID_ATTRIBUTES    0x000007F2L


	typedef struct _OBJECT_ATTRIBUTES {
		ULONG Length;
		HANDLE RootDirectory;
		PUNICODE_STRING ObjectName;
		ULONG Attributes;
		PVOID SecurityDescriptor;        // Points to type SECURITY_DESCRIPTOR
		PVOID SecurityQualityOfService;  // Points to type SECURITY_QUALITY_OF_SERVICE
	} OBJECT_ATTRIBUTES;
	typedef OBJECT_ATTRIBUTES *POBJECT_ATTRIBUTES;

	#define InitializeObjectAttributes( p, n, a, r, s ) { \
		(p)->Length = sizeof( OBJECT_ATTRIBUTES );        \
		(p)->RootDirectory = r;                           \
		(p)->Attributes = a;                              \
		(p)->ObjectName = n;                              \
		(p)->SecurityDescriptor = s;                      \
		(p)->SecurityQualityOfService = NULL;             \
		}
		
	#define RtlFillMemory(Destination,Length,Fill) memset((Destination),(Fill),(Length))
	#define RtlZeroMemory(Destination,Length) memset((Destination),0,(Length))
	#define RtlCopyMemory(Destination,Source,Length) memcpy((Destination),(Source),(Length))
	#define RtlMoveMemory(Destination,Source,Length) memmove((Destination),(Source),(Length))

	typedef NTSTATUS(STDAPICALLTYPE RTLINITSTRING)
		(
			IN OUT PSTRING DestinationString,
			IN LPCSTR SourceString
			);
	typedef RTLINITSTRING FAR * LPRTLINITSTRING;

	typedef NTSTATUS(STDAPICALLTYPE RTLINITANSISTRING)
		(
			IN OUT PANSI_STRING DestinationString,
			IN LPCSTR SourceString
			);
	typedef RTLINITANSISTRING FAR * LPRTLINITANSISTRING;

	typedef NTSTATUS(STDAPICALLTYPE RTLINITUNICODESTRING)
		(
			IN OUT PUNICODE_STRING DestinationString,
			IN LPCWSTR SourceString
			);
	typedef RTLINITUNICODESTRING FAR * LPRTLINITUNICODESTRING;

	typedef NTSTATUS(STDAPICALLTYPE RTLANSISTRINGTOUNICODESTRING)
		(
			IN OUT PUNICODE_STRING	DestinationString,
			IN PANSI_STRING			SourceString,
			IN BOOLEAN				AllocateDestinationString
			);
	typedef RTLANSISTRINGTOUNICODESTRING FAR * LPRTLANSISTRINGTOUNICODESTRING;

	typedef NTSTATUS(STDAPICALLTYPE RTLUNICODESTRINGTOANSISTRING)
		(
			IN OUT PANSI_STRING		DestinationString,
			IN PUNICODE_STRING		SourceString,
			IN BOOLEAN				AllocateDestinationString
			);
	typedef RTLUNICODESTRINGTOANSISTRING FAR * LPRTLUNICODESTRINGTOANSISTRING;

	typedef NTSTATUS(STDAPICALLTYPE RTLFREESTRING)
		(
			IN PSTRING String
			);
	typedef RTLFREESTRING FAR * LPRTLFREESTRING;

	typedef NTSTATUS(STDAPICALLTYPE RTLFREEANSISTRING)
		(
			IN PANSI_STRING AnsiString
			);
	typedef RTLFREEANSISTRING FAR * LPRTLFREEANSISTRING;

	typedef NTSTATUS(STDAPICALLTYPE RTLFREEUNICODESTRING)
		(
			IN PUNICODE_STRING UnicodeString
			);
	typedef RTLFREEUNICODESTRING FAR * LPRTLFREEUNICODESTRING;

	typedef NTSTATUS(STDAPICALLTYPE RTLCONVERTSIDTOUNICODESTRING)(
		OUT PUNICODE_STRING UnicodeString,
		IN  PSID            Sid,
		IN  BOOLEAN         AllocateDestinationString
		);
	typedef RTLCONVERTSIDTOUNICODESTRING FAR * LPRTLCONVERTSIDTOUNICODESTRING;

	typedef BOOL(WINAPI GETTOKENINFORMATION)
		(
			_In_      HANDLE                  TokenHandle,
			_In_      TOKEN_INFORMATION_CLASS TokenInformationClass,
			_Out_opt_ LPVOID                  TokenInformation,
			_In_      DWORD                   TokenInformationLength,
			_Out_     PDWORD                  ReturnLength
			);
	typedef GETTOKENINFORMATION FAR * LPGETTOKENINFORMATION;

	typedef BOOL(WINAPI OPENPROCESSTOKEN)
		(
			_In_  HANDLE  ProcessHandle,
			_In_  DWORD   DesiredAccess,
			_Out_ PHANDLE TokenHandle
			);
	typedef OPENPROCESSTOKEN FAR * LPOPENPROCESSTOKEN;

	typedef BOOL(WINAPI OPENTHREADTOKEN)
		(
			_In_  HANDLE  ThreadHandle,
			_In_  DWORD   DesiredAccess,
			_In_  BOOL    OpenAsSelf,
			_Out_ PHANDLE TokenHandle
			);
	typedef OPENTHREADTOKEN FAR * LPOPENTHREADTOKEN;

	typedef NTSTATUS(STDAPICALLTYPE NTCREATEKEY)
		(
			IN HANDLE				KeyHandle,
			IN ULONG				DesiredAccess,
			IN POBJECT_ATTRIBUTES	ObjectAttributes,
			IN ULONG				TitleIndex,
			IN PUNICODE_STRING		Class,			/* optional*/
			IN ULONG				CreateOptions,
			OUT PULONG				Disposition		/* optional*/
			);
	typedef NTCREATEKEY FAR * LPNTCREATEKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTOPENKEY)
		(
			IN HANDLE				KeyHandle,
			IN ULONG				DesiredAccess,
			IN POBJECT_ATTRIBUTES	ObjectAttributes
			);
	typedef NTOPENKEY FAR * LPNTOPENKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTFLUSHKEY)
		(
			IN HANDLE KeyHandle
			);
	typedef NTFLUSHKEY FAR * LPNTFLUSHKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTDELETEKEY)
		(
			IN HANDLE KeyHandle
			);
	typedef NTDELETEKEY FAR * LPNTDELETEKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTSETVALUEKEY)
		(
			IN HANDLE			KeyHandle,
			IN PUNICODE_STRING	ValueName,
			IN ULONG			TitleIndex,			/* optional */
			IN ULONG			Type,
			IN PVOID			Data,
			IN ULONG			DataSize
			);
	typedef NTSETVALUEKEY FAR * LPNTSETVALUEKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTQUERYVALUEKEY)
		(
			// Is the handle, returned by a successful 
			// call to NtCreateKey or NtOpenKey, of key 
			// for which value entries are to be read.
			IN HANDLE			KeyHandle,
			IN PUNICODE_STRING	ValueName,
			IN KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
			OUT PVOID			KeyValueInformation,
			IN ULONG			Length,
			OUT PULONG			ResultLength
			);
	typedef NTQUERYVALUEKEY FAR * LPNTQUERYVALUEKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTSETINFORMATIONKEY)
		(
			IN HANDLE	KeyHandle,
			IN KEY_SET_INFORMATION_CLASS KeyInformationClass,
			IN PVOID	KeyInformation,
			IN ULONG	KeyInformationLength
			);
	typedef NTSETINFORMATIONKEY FAR * LPNTSETINFORMATIONKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTQUERYKEY)
		(
			IN HANDLE	KeyHandle,
			IN KEY_INFORMATION_CLASS KeyInformationClass,
			OUT PVOID	KeyInformation,
			IN ULONG	KeyInformationLength,
			OUT PULONG	ResultLength
			);
	typedef NTQUERYKEY FAR * LPNTQUERYKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTENUMERATEKEY)
		(
			IN HANDLE	KeyHandle,
			IN ULONG	Index,
			IN KEY_INFORMATION_CLASS KeyInformationClass,
			OUT PVOID	KeyInformation,
			IN ULONG	KeyInformationLength,
			OUT PULONG	ResultLength
			);
	typedef NTENUMERATEKEY FAR * LPNTENUMERATEKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTDELETEVALUEKEY)
		(
			IN HANDLE			KeyHandle,
			IN PUNICODE_STRING	ValueName
			);
	typedef NTDELETEVALUEKEY FAR * LPNTDELETEVALUEKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTENUMERATEVALUEKEY)
		(
			IN HANDLE	KeyHandle,
			IN ULONG	Index,
			IN KEY_VALUE_INFORMATION_CLASS KeyValueInformationClass,
			OUT PVOID	KeyValueInformation,
			IN ULONG	KeyValueInformationLength,
			OUT PULONG	ResultLength
			);
	typedef NTENUMERATEVALUEKEY FAR * LPNTENUMERATEVALUEKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTQUERYMULTIPLEVALUEKEY)
		(
			IN HANDLE		KeyHandle,
			IN OUT PKEY_MULTIPLE_VALUE_INFORMATION ValuesList,
			IN ULONG		NumberOfValues,
			OUT PVOID		DataBuffer,
			IN OUT ULONG	BufferLength,
			OUT PULONG		RequiredLength			/* optional */
			);
	typedef NTQUERYMULTIPLEVALUEKEY FAR * LPNTQUERYMULTIPLEVALUEKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTNOTIFYCHANGEKEY)
		(
			IN HANDLE				KeyHandle,
			IN HANDLE				EventHandle,
			IN PIO_APC_ROUTINE		ApcRoutine,
			IN PVOID				ApcRoutineContext,
			IN PIO_STATUS_BLOCK		IoStatusBlock,
			IN ULONG				NotifyFilter,
			IN BOOLEAN				WatchSubtree,
			OUT PVOID				RegChangesDataBuffer,
			IN ULONG				RegChangesDataBufferLength,
			IN BOOLEAN				Asynchronous
			);
	typedef NTNOTIFYCHANGEKEY FAR * LPNTNOTIFYCHANGEKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTRENAMEKEY)
		(
			IN HANDLE			KeyHandle,
			IN PUNICODE_STRING	ReplacementName
			);
	typedef NTRENAMEKEY FAR * LPNTRENAMEKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTRESTOREKEY)
		(
			IN HANDLE	KeyHandle,
			IN HANDLE	FileHandle,
			IN ULONG	RestoreOption
			);
	typedef NTRESTOREKEY FAR * LPNTRESTOREKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTSAVEKEY)
		(
			IN HANDLE	KeyHandle,
			IN HANDLE	FileHandle
			);
	typedef NTSAVEKEY FAR * LPNTSAVEKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTLOADKEY)
		(
			IN POBJECT_ATTRIBUTES DestinationKeyName,	// - and HANDLE to root key.
														//   Root can be \registry\machine 
														//   or \registry\user. 
														//   All other keys are invalid. 
			IN POBJECT_ATTRIBUTES HiveFileName			// - Hive file path and name
			);
	typedef NTLOADKEY FAR * LPNTLOADKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTLOADKEY2)
		(
			IN POBJECT_ATTRIBUTES DestinationKeyName,
			IN POBJECT_ATTRIBUTES HiveFileName,
			IN ULONG Flags	// Flags can be 0x0000 or REG_NO_LAZY_FLUSH (0x0004)
			);
	typedef NTLOADKEY2 FAR * LPNTLOADKEY2;

	typedef NTSTATUS(STDAPICALLTYPE NTREPLACEKEY)
		(
			IN POBJECT_ATTRIBUTES	NewHiveFileName,
			IN HANDLE				KeyHandle,
			IN POBJECT_ATTRIBUTES	BackupHiveFileName
			);
	typedef NTREPLACEKEY FAR * LPNTREPLACEKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTUNLOADKEY)
		(
			IN POBJECT_ATTRIBUTES	DestinationKeyName
			);
	typedef NTUNLOADKEY FAR * LPNTUNLOADKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTCLOSE)
		(
			IN HANDLE KeyHandle
			);
	typedef NTCLOSE FAR * LPNTCLOSE;

	typedef NTSTATUS(STDAPICALLTYPE NTCREATEFILE)
		(
			OUT PHANDLE             FileHandle,
			IN ACCESS_MASK          DesiredAccess,
			IN POBJECT_ATTRIBUTES   ObjectAttributes,
			OUT PIO_STATUS_BLOCK    IoStatusBlock,
			IN PLARGE_INTEGER       AllocationSize,		/* optional */
			IN ULONG                FileAttributes,
			IN ULONG                ShareAccess,
			IN ULONG                CreateDisposition,
			IN ULONG                CreateOptions,
			IN PVOID                EaBuffer,			/* optional */
			IN ULONG                EaLength
			);
	typedef NTCREATEFILE FAR * LPNTCREATEFILE;

	typedef NTSTATUS(STDAPICALLTYPE NTOPENTHREAD)
		(
			OUT PHANDLE				ThreadHandle,
			IN ACCESS_MASK			DesiredAccess,
			IN POBJECT_ATTRIBUTES	ObjectAttributes,
			IN PCLIENT_ID			ClientId		/* optional*/
			);
	typedef NTOPENTHREAD FAR * LPNTOPENTHREAD;

	typedef NTSTATUS(STDAPICALLTYPE NTOPENPROCESSTOKEN)
		(
			IN HANDLE               ProcessHandle,
			IN ACCESS_MASK          DesiredAccess,
			OUT PHANDLE             TokenHandle
			);
	typedef NTOPENPROCESSTOKEN FAR * LPNTOPENPROCESSTOKEN;

	typedef NTSTATUS(STDAPICALLTYPE NTADJUSTPRIVILEGESTOKEN)
		(
			IN HANDLE               TokenHandle,
			IN BOOLEAN              DisableAllPrivileges,
			IN PTOKEN_PRIVILEGES    TokenPrivileges,
			IN ULONG                PreviousPrivilegesLength,
			OUT PTOKEN_PRIVILEGES   PreviousPrivileges,	/* optional */
			OUT PULONG              RequiredLength		/* optional */
			);
	typedef NTADJUSTPRIVILEGESTOKEN FAR * LPNTADJUSTPRIVILEGESTOKEN;

	typedef NTSTATUS(STDAPICALLTYPE NTQUERYINFORMATIONTOKEN)
		(
			IN HANDLE TokenHandle,
			IN TOKEN_INFORMATION_CLASS TokenInformationClass,
			OUT PVOID TokenInformation,
			IN ULONG TokenInformationLength,
			OUT PULONG ReturnLength
			);
	typedef NTQUERYINFORMATIONTOKEN FAR * LPNTQUERYINFORMATIONTOKEN;

	typedef NTSTATUS(STDAPICALLTYPE RTLALLOCATEHEAP)
		(
			IN PVOID HeapHandle,
			IN ULONG Flags,
			IN ULONG Size
			);
	typedef RTLALLOCATEHEAP FAR * LPRTLALLOCATEHEAP;

	typedef NTSTATUS(STDAPICALLTYPE RTLFREEHEAP)
		(
			IN PVOID HeapHandle,
			IN ULONG Flags,								/* optional */
			IN PVOID MemoryPointer
			);
	typedef RTLFREEHEAP FAR * LPRTLFREEHEAP;

	typedef NTSTATUS(STDAPICALLTYPE NTCOMPACTKEYS)
		(
			IN ULONG NrOfKeys,
			IN HANDLE KeysArray
			);
	typedef NTCOMPACTKEYS FAR * LPNTCOMPACTKEYS;

	typedef NTSTATUS(STDAPICALLTYPE NTCOMPRESSKEY)
		(
			IN HANDLE Key
			);
	typedef NTCOMPRESSKEY FAR * LPNTCOMPRESSKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTLOCKREGISTRYKEY)
		(
			IN HANDLE KeyHandle
			);
	typedef NTLOCKREGISTRYKEY FAR * LPNTLOCKREGISTRYKEY;

	typedef NTSTATUS(STDAPICALLTYPE NTQUERYOPENSUBKEYSEX)
		(
			IN POBJECT_ATTRIBUTES TargetKey,
			IN ULONG BufferLength,
			IN PVOID Buffer,
			IN PULONG RequiredSize
			);
	typedef NTQUERYOPENSUBKEYSEX FAR * LPNTQUERYOPENSUBKEYSEX;

	typedef NTSTATUS(STDAPICALLTYPE NTSAVEKEYEX)
		(
			IN HANDLE KeyHandle,
			IN HANDLE FileHandle,
			IN ULONG Flags
			);
	typedef NTSAVEKEYEX FAR * LPNTSAVEKEYEX;

	typedef NTSTATUS(STDAPICALLTYPE NTLOADKEYEX)
		(
			IN POBJECT_ATTRIBUTES TargetKey,
			IN POBJECT_ATTRIBUTES SourceFile,
			IN ULONG Flags,
			IN HANDLE TrustClassKey
			);
	typedef NTLOADKEYEX FAR * LPNTLOADKEYEX;

	typedef NTSTATUS(STDAPICALLTYPE NTUNLOADKEY2)
		(
			IN POBJECT_ATTRIBUTES TargetKey,
			IN ULONG Flags
			);
	typedef NTUNLOADKEY2 FAR * LPNTUNLOADKEY2;

	typedef NTSTATUS(STDAPICALLTYPE NTUNLOADKEYEX)
		(
			IN POBJECT_ATTRIBUTES TargetKey,
			IN HANDLE Event
			);
	typedef NTUNLOADKEYEX FAR * LPNTUNLOADKEYEX;

	typedef enum _OBJECT_INFORMATION_CLASS {
		ObjectBasicInformation = 0,
		ObjectTypeInformation = 2
	} OBJECT_INFORMATION_CLASS;


	typedef NTSTATUS(STDAPICALLTYPE NTQUERYOBJECT)
		(
			_In_opt_  HANDLE                   Handle,
			_In_      OBJECT_INFORMATION_CLASS ObjectInformationClass,
			_Out_opt_ PVOID                    ObjectInformation,
			_In_      ULONG                    ObjectInformationLength,
			_Out_opt_ PULONG                   ReturnLength
			);
	typedef NTQUERYOBJECT FAR * LPNTQUERYOBJECT;


	public ref class Registry sealed
	{
	private:

		property LPGETTOKENINFORMATION			GetTokenInformation;
		property LPOPENPROCESSTOKEN				OpenProcessToken;
		property LPOPENTHREADTOKEN				OpenThreadToken;
		property LPNTCREATEKEY				NtCreateKey;
		property LPNTOPENKEY				NtOpenKey;
		property LPNTDELETEKEY				NtDeleteKey;
		property LPNTFLUSHKEY				NtFlushKey;
		property LPNTQUERYKEY				NtQueryKey;
		property LPNTENUMERATEKEY			NtEnumerateKey;
		property LPNTSETVALUEKEY			NtSetValueKey;
		property LPNTSETINFORMATIONKEY		NtSetInformationKey;
		property LPNTQUERYVALUEKEY			NtQueryValueKey;
		property LPNTENUMERATEVALUEKEY		NtEnumerateValueKey;
		property LPNTDELETEVALUEKEY			NtDeleteValueKey;
		property LPNTQUERYMULTIPLEVALUEKEY	NtQueryMultipleValueKey;
		property LPNTRENAMEKEY				NtRenameKey;
		property LPNTCOMPACTKEYS			NtCompactKeys;
		property LPNTCOMPRESSKEY			NtCompressKey;
		property LPNTLOCKREGISTRYKEY		NtLockRegistryKey;
		property LPNTQUERYOPENSUBKEYSEX		NtQueryOpenSubKeysEx;
		property LPNTSAVEKEYEX				NtSaveKeyEx;
		property LPNTLOADKEYEX				NtLoadKeyEx;
		property LPNTUNLOADKEY2				NtUnloadKey2;
		property LPNTUNLOADKEYEX			NtUnloadKeyEx;
		property LPNTSAVEKEY				NtSaveKey;
		property LPNTRESTOREKEY				NtRestoreKey;
		property LPNTLOADKEY				NtLoadKey;
		property LPNTLOADKEY2				NtLoadKey2;
		property LPNTREPLACEKEY				NtReplaceKey;
		property LPNTUNLOADKEY				NtUnloadKey;
		property LPNTCLOSE					NtClose;
		property LPNTNOTIFYCHANGEKEY		NtNotifyChangeKey;
		property LPNTOPENTHREAD				NtOpenThread;
		property LPNTCREATEFILE				NtCreateFile;
		property LPNTOPENPROCESSTOKEN		NtOpenProcessToken;
		property LPNTADJUSTPRIVILEGESTOKEN	NtAdjustPrivilegesToken;
		property LPNTQUERYINFORMATIONTOKEN	NtQueryInformationToken;
		property LPRTLINITSTRING				RtlInitString;
		property LPRTLINITANSISTRING			RtlInitAnsiString;
		property LPRTLINITUNICODESTRING			RtlInitUnicodeString;
		property LPRTLANSISTRINGTOUNICODESTRING	RtlAnsiStringToUnicodeString;
		property LPRTLUNICODESTRINGTOANSISTRING	RtlUnicodeStringToAnsiString;
		property LPRTLFREESTRING				RtlFreeString;
		property LPRTLFREEANSISTRING			RtlFreeAnsiString;
		property LPRTLFREEUNICODESTRING			RtlFreeUnicodeString;
		property LPRTLCONVERTSIDTOUNICODESTRING	RtlConvertSidToUnicodeString;
		property LPRTLALLOCATEHEAP			RtlAllocateHeap;
		property LPRTLFREEHEAP				RtlFreeHeap;
		property LPNTQUERYOBJECT	NtQueryObject;

	public:
		Registry();
		void	Registry::InitNTDLLEntryPoints();

		RegistryType Registry::GetValueInfo(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, int nSize);

		Platform::Boolean Registry::GetSubKeyList(RegistryHive Hive, Platform::String^ Key, Platform::Array<Platform::String^> ^*csaSubkeys);
		Platform::Boolean Registry::GetValueList(RegistryHive Hive, Platform::String^ Key, Platform::Array<Platform::String^> ^*csaValues);

		Platform::Boolean Registry::ValueExists(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name);

		Platform::Boolean Registry::WriteValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, const Platform::Array<uint8>^ csaValue, RegistryType type);
		Platform::Boolean Registry::QueryValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, RegistryType* RegType, Platform::Array<uint8>^* RetBuffer);

		Platform::Boolean Registry::RenameKey(RegistryHive Hive, Platform::String^ Key, Platform::String^ csNewKeyName);

		Platform::Boolean Registry::DeleteKey(RegistryHive Hive, Platform::String^ Key);
		Platform::Boolean Registry::DeleteKeysRecursive(RegistryHive Hive, Platform::String^ Key);

		Platform::Boolean Registry::CreateKey(RegistryHive Hive, Platform::String^ Key);

		Platform::Boolean Registry::DeleteValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name);
		unsigned int Registry::GetKeyStatus(RegistryHive Hive, Platform::String^ Key);
		Platform::Boolean Registry::FindHiddenKeys(RegistryHive Hive, Platform::String^ Key, Platform::Array<Platform::String^> ^*csaSubkeys);
		Platform::Boolean Registry::IsKeyHidden(RegistryHive Hive, Platform::String^ Key);
		Platform::Boolean Registry::GetKeyLastWriteTime(RegistryHive Hive, Platform::String^ Key, int64 *LastWriteTime);

		//Customs
		Platform::Boolean Registry::WriteValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, const Platform::Array<uint8>^ csaValue, uint32 type);
		unsigned int Registry::GetValueInfo2(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, int nSize);
		Platform::Boolean Registry::QueryValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, uint32* RegType, Platform::Array<uint8>^* RetBuffer);

		Platform::Boolean Registry::LoadHive(Platform::String^ HiveFile, Platform::String^ MountName, Platform::Boolean InUser);
		Platform::Boolean Registry::UnloadHive(Platform::String^ KeyPath, Platform::Boolean InUser);

	private:
		Platform::String^ Registry::GetCurrentUserSID();
		Platform::String^ Registry::GetRootPathFor(RegistryHive hRoot);
		BOOL Registry::ReadValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, RegistryType RegType, KEY_VALUE_PARTIAL_INFORMATION** retInfo);
		Platform::Boolean Registry::WriteValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, PVOID pValue, ULONG ulValueLength, RegistryType dwRegType);

		// Customs
		Platform::Boolean Registry::WriteValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, PVOID pValue, RegistryRT::ULONG ulValueLength, DWORD dwRegType);
		BOOL Registry::ReadValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, uint32 RegType, KEY_VALUE_PARTIAL_INFORMATION** retInfo);
	};
}
