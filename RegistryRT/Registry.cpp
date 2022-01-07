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
#include "pch.h"
#include "Registry.h"

using namespace RegistryRT;
using namespace Platform;

Registry::Registry()
{

}

void Registry::InitNTDLLEntryPoints()
{
	NtOpenThread = (LPNTOPENTHREAD)GetProcAddress("NTDLL.DLL", "NtOpenThread");
	if (!NtOpenThread) {
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));
	}
	NtCreateKey = (LPNTCREATEKEY)GetProcAddress("NTDLL.DLL", "NtCreateKey");
	if (!NtCreateKey) {
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));
	}
	NtOpenKey = (LPNTOPENKEY)GetProcAddress("NTDLL.DLL", "NtOpenKey");
	if (!NtOpenKey) {
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtFlushKey = (LPNTFLUSHKEY)GetProcAddress("NTDLL.DLL", "NtFlushKey");
	if (!NtFlushKey) {
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtDeleteKey = (LPNTDELETEKEY)GetProcAddress("NTDLL.DLL", "NtDeleteKey");
	if (!NtDeleteKey) {
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtQueryKey = (LPNTQUERYKEY)GetProcAddress("NTDLL.DLL", "NtQueryKey");
	if (!NtQueryKey) {
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtEnumerateKey = (LPNTENUMERATEKEY)GetProcAddress("NTDLL.DLL", "NtEnumerateKey");
	if (!NtEnumerateKey) {
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtClose = (LPNTCLOSE)GetProcAddress("NTDLL.DLL", "NtClose");
	if (!NtClose) {
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtSetValueKey = (LPNTSETVALUEKEY)GetProcAddress("NTDLL.DLL", "NtSetValueKey");
	if (!NtSetValueKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtSetInformationKey = (LPNTSETINFORMATIONKEY)GetProcAddress("NTDLL.DLL", "NtSetInformationKey");
	if (!NtSetInformationKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtQueryValueKey = (LPNTQUERYVALUEKEY)GetProcAddress("NTDLL.DLL", "NtQueryValueKey");
	if (!NtQueryValueKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtEnumerateValueKey = (LPNTENUMERATEVALUEKEY)GetProcAddress("NTDLL.DLL", "NtEnumerateValueKey");
	if (!NtEnumerateValueKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtDeleteValueKey = (LPNTDELETEVALUEKEY)GetProcAddress("NTDLL.DLL", "NtDeleteValueKey");
	if (!NtDeleteValueKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtRenameKey = (LPNTRENAMEKEY)GetProcAddress("NTDLL.DLL", "NtRenameKey");
	if (!NtDeleteValueKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtQueryMultipleValueKey = (LPNTQUERYMULTIPLEVALUEKEY)GetProcAddress("NTDLL.DLL", "NtQueryMultipleValueKey");
	if (!NtQueryMultipleValueKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtNotifyChangeKey = (LPNTNOTIFYCHANGEKEY)GetProcAddress("NTDLL.DLL", "NtNotifyChangeKey");
	if (!NtNotifyChangeKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtCreateFile = (LPNTCREATEFILE)GetProcAddress("NTDLL.DLL", "NtCreateFile");
	if (!NtCreateFile)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtOpenProcessToken = (LPNTOPENPROCESSTOKEN)GetProcAddress("NTDLL.DLL", "NtOpenProcessToken");
	if (!NtOpenProcessToken)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtAdjustPrivilegesToken = (LPNTADJUSTPRIVILEGESTOKEN)GetProcAddress("NTDLL.DLL", "NtAdjustPrivilegesToken");
	if (!NtAdjustPrivilegesToken)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtQueryInformationToken = (LPNTQUERYINFORMATIONTOKEN)GetProcAddress("NTDLL.DLL", "NtQueryInformationToken");
	if (!NtQueryInformationToken)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	RtlAllocateHeap = (LPRTLALLOCATEHEAP)GetProcAddress("NTDLL.DLL", "RtlAllocateHeap");
	if (!RtlAllocateHeap)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	RtlFreeHeap = (LPRTLFREEHEAP)GetProcAddress("NTDLL.DLL", "RtlFreeHeap");
	if (!RtlFreeHeap)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtRestoreKey = (LPNTRESTOREKEY)GetProcAddress("NTDLL.DLL", "NtRestoreKey");
	if (!NtRestoreKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtSaveKey = (LPNTSAVEKEY)GetProcAddress("NTDLL.DLL", "NtSaveKey");
	if (!NtSaveKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtLoadKey = (LPNTLOADKEY)GetProcAddress("NTDLL.DLL", "NtLoadKey");
	if (!NtLoadKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtLoadKey2 = (LPNTLOADKEY2)GetProcAddress("NTDLL.DLL", "NtLoadKey2");
	if (!NtLoadKey2)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtReplaceKey = (LPNTREPLACEKEY)GetProcAddress("NTDLL.DLL", "NtReplaceKey");
	if (!NtReplaceKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtUnloadKey = (LPNTUNLOADKEY)GetProcAddress("NTDLL.DLL", "NtUnloadKey");
	if (!NtUnloadKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtCompactKeys = (LPNTCOMPACTKEYS)GetProcAddress("NTDLL.DLL", "NtCompactKeys");
	if (!NtCompactKeys)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtCompressKey = (LPNTCOMPRESSKEY)GetProcAddress("NTDLL.DLL", "NtCompressKey");
	if (!NtCompressKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtLockRegistryKey = (LPNTLOCKREGISTRYKEY)GetProcAddress("NTDLL.DLL", "NtLockRegistryKey");
	if (!NtLockRegistryKey)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtQueryOpenSubKeysEx = (LPNTQUERYOPENSUBKEYSEX)GetProcAddress("NTDLL.DLL", "NtQueryOpenSubKeysEx");
	if (!NtQueryOpenSubKeysEx)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtSaveKeyEx = (LPNTSAVEKEYEX)GetProcAddress("NTDLL.DLL", "NtSaveKeyEx");
	if (!NtSaveKeyEx)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtLoadKeyEx = (LPNTLOADKEYEX)GetProcAddress("NTDLL.DLL", "NtLoadKeyEx");
	if (!NtLoadKeyEx)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtUnloadKey2 = (LPNTUNLOADKEY2)GetProcAddress("NTDLL.DLL", "NtUnloadKey2");
	if (!NtUnloadKey2)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	NtUnloadKeyEx = (LPNTUNLOADKEYEX)GetProcAddress("NTDLL.DLL", "NtUnloadKeyEx");
	if (!NtUnloadKeyEx)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}

	RtlInitString = (LPRTLINITSTRING)GetProcAddress("NTDLL.DLL", "RtlInitString");
	RtlInitAnsiString = (LPRTLINITANSISTRING)GetProcAddress("NTDLL.DLL", "RtlInitAnsiString");
	RtlInitUnicodeString = (LPRTLINITUNICODESTRING)GetProcAddress("NTDLL.DLL", "RtlInitUnicodeString");
	RtlAnsiStringToUnicodeString = (LPRTLANSISTRINGTOUNICODESTRING)GetProcAddress("NTDLL.DLL", "RtlAnsiStringToUnicodeString");
	RtlUnicodeStringToAnsiString = (LPRTLUNICODESTRINGTOANSISTRING)GetProcAddress("NTDLL.DLL", "RtlUnicodeStringToAnsiString");
	RtlFreeString = (LPRTLFREESTRING)GetProcAddress("NTDLL.DLL", "RtlFreeString");
	RtlFreeAnsiString = (LPRTLFREEANSISTRING)GetProcAddress("NTDLL.DLL", "RtlFreeAnsiString");
	RtlFreeUnicodeString = (LPRTLFREEUNICODESTRING)GetProcAddress("NTDLL.DLL", "RtlFreeUnicodeString");
	RtlConvertSidToUnicodeString = (LPRTLCONVERTSIDTOUNICODESTRING)GetProcAddress("NTDLL.DLL", "RtlConvertSidToUnicodeString");
	if (!RtlInitString && !RtlInitAnsiString && !RtlInitUnicodeString &&
		!RtlAnsiStringToUnicodeString && !RtlUnicodeStringToAnsiString &&
		!RtlFreeString && !RtlFreeAnsiString && !RtlFreeUnicodeString && !RtlConvertSidToUnicodeString)
	{
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));
	}

	GetTokenInformation = (LPGETTOKENINFORMATION)GetProcAddress("kernelbase.dll", "GetTokenInformation");
	OpenProcessToken = (LPOPENPROCESSTOKEN)GetProcAddress("kernelbase.dll", "OpenProcessToken");
	OpenThreadToken = (LPOPENTHREADTOKEN)GetProcAddress("kernelbase.dll", "OpenThreadToken");
	if (GetTokenInformation && OpenProcessToken && OpenThreadToken)
	{
		GetTokenInformation = (LPGETTOKENINFORMATION)GetProcAddress("Advapi32.dll", "GetTokenInformation");
		OpenProcessToken = (LPOPENPROCESSTOKEN)GetProcAddress("Advapi32.dll", "OpenProcessToken");
		OpenThreadToken = (LPOPENTHREADTOKEN)GetProcAddress("Advapi32.dll", "OpenThreadToken");
		if (!GetTokenInformation && !OpenProcessToken && !OpenThreadToken)
		{
			throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));
		}
	}
}

Platform::Boolean Registry::IsKeyHidden(RegistryHive Hive, Platform::String^ Key)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	uKey.Length += 2;
	uKey.MaximumLength += 2;

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	//
	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, GENERIC_READ, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {
		RtlFreeUnicodeString(&uKey);
		return FALSE;
	}
	NtClose(hKey);

	RtlFreeUnicodeString(&uKey);
	return TRUE;
}

Platform::Boolean Registry::FindHiddenKeys(RegistryHive Hive, Platform::String^ Key, Platform::Array<Platform::String^> ^*csaSubkeys)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	//
	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, KEY_ENUMERATE_SUB_KEYS, &ObjectAttributes);
	if (NT_SUCCESS(m_NtStatus)) {
		//
		ULONG resultLength;
		CHAR szSubkeyInfo[1024];
		UINT i = 0;

		Platform::String^ csSubkey, ^csNewSubkey;

		std::vector<Platform::String^> Subkeys;

		// Scan for subkeys
		while ((m_NtStatus = NtEnumerateKey(hKey, i, KeyBasicInformation, szSubkeyInfo, sizeof(szSubkeyInfo), &resultLength)) == STATUS_SUCCESS)
		{
			// Copy the Data into the structure so we can use it
			PKEY_BASIC_INFORMATION tInfo = (PKEY_BASIC_INFORMATION)szSubkeyInfo;

			// put the subkey name into a variable
			csSubkey = ref new Platform::String(tInfo->Name);
			// now create a new subkey that we need to check

			csNewSubkey = Key + L"\\" + ref new String(csSubkey->Data(), tInfo->NameLength / 2);

			if (IsKeyHidden(Hive, csNewSubkey)) {
				Subkeys.push_back(csNewSubkey);
			}

			i++;
		}
		NtClose(hKey);

		*csaSubkeys = ref new Platform::Array<Platform::String^>(Subkeys.data(), Subkeys.size());
	}

	RtlFreeUnicodeString(&uKey);

	return TRUE;
}

Platform::Boolean Registry::QueryValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, RegistryType* RegType, Platform::Array<uint8>^* RetBuffer)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cName = (PWSTR)Name->Data();
	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	HANDLE hKey;

	NTSTATUS m_NtStatus = NtOpenKey(&hKey, GENERIC_READ, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {
		RegistryType tmp = RegistryType::None;
		RegType = &tmp;
		*RetBuffer = ref new Platform::Array<uint8>(NULL);

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	UNICODE_STRING ValueName;
	RtlInitUnicodeString(&ValueName, cName);

	BYTE *Buffer;
	DWORD dwDataSize = 0;

	KEY_VALUE_PARTIAL_INFORMATION *info;

	m_NtStatus = STATUS_SUCCESS;

	if (NtQueryValueKey(hKey, &ValueName, KeyValuePartialInformation,
		NULL, 0, &dwDataSize) == STATUS_BUFFER_OVERFLOW)
	{
		do {
			Buffer = (BYTE*)HeapAlloc(GetProcessHeap(), 0, dwDataSize + 1024 + sizeof(WCHAR));
			if (!Buffer) {
				NtClose(hKey);
				RegistryType tmp = RegistryType::None;
				RegType = &tmp;
				*RetBuffer = ref new Platform::Array<uint8>(NULL);
				return FALSE;
			}

			m_NtStatus = NtQueryValueKey(hKey, &ValueName, KeyValuePartialInformation,
				Buffer, dwDataSize, &dwDataSize);

		} while (m_NtStatus == STATUS_BUFFER_OVERFLOW);
	}
	else
	{
		Buffer = (BYTE*)HeapAlloc(GetProcessHeap(), 0, dwDataSize + 1024);
		if (!Buffer) {
			NtClose(hKey);
			RegistryType tmp = RegistryType::None;
			RegType = &tmp;
			*RetBuffer = ref new Platform::Array<uint8>(NULL);
			return FALSE;
		}

		m_NtStatus = NtQueryValueKey(hKey,
			&ValueName,
			KeyValuePartialInformation,
			Buffer,
			dwDataSize,
			&dwDataSize);

	}

	if (!NT_SUCCESS(m_NtStatus)) {
		RegistryType tmp = RegistryType::None;
		RegType = &tmp;
		*RetBuffer = ref new Platform::Array<uint8>(NULL);
		return FALSE;
	}

	info = (KEY_VALUE_PARTIAL_INFORMATION *)Buffer;

	NtClose(hKey);

	RegistryType tmp = static_cast<RegistryType>(info->Type);
	*RegType = tmp;

	*RetBuffer = ref new Platform::Array<uint8>(info->Data, info->DataLength);
	return TRUE;
}

Platform::Boolean Registry::QueryValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, uint32* RegType, Platform::Array<uint8>^* RetBuffer)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cName = (PWSTR)Name->Data();
	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	HANDLE hKey;

	NTSTATUS m_NtStatus = NtOpenKey(&hKey, GENERIC_READ, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {
		uint32 tmp = 0;
		RegType = &tmp;
		*RetBuffer = ref new Platform::Array<uint8>(NULL);

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	UNICODE_STRING ValueName;
	RtlInitUnicodeString(&ValueName, cName);

	BYTE *Buffer;
	DWORD dwDataSize = 0;

	KEY_VALUE_PARTIAL_INFORMATION *info;

	m_NtStatus = STATUS_SUCCESS;

	if (NtQueryValueKey(hKey, &ValueName, KeyValuePartialInformation,
		NULL, 0, &dwDataSize) == STATUS_BUFFER_OVERFLOW)
	{
		do {
			Buffer = (BYTE*)HeapAlloc(GetProcessHeap(), 0, dwDataSize + 1024 + sizeof(WCHAR));
			if (!Buffer) {
				NtClose(hKey);
				uint32 tmp = 0;
				RegType = &tmp;
				*RetBuffer = ref new Platform::Array<uint8>(NULL);
				return FALSE;
			}

			m_NtStatus = NtQueryValueKey(hKey, &ValueName, KeyValuePartialInformation,
				Buffer, dwDataSize, &dwDataSize);

		} while (m_NtStatus == STATUS_BUFFER_OVERFLOW);
	}
	else
	{
		Buffer = (BYTE*)HeapAlloc(GetProcessHeap(), 0, dwDataSize + 1024);
		if (!Buffer) {
			NtClose(hKey);
			uint32 tmp = 0;
			RegType = &tmp;
			*RetBuffer = ref new Platform::Array<uint8>(NULL);
			return FALSE;
		}

		m_NtStatus = NtQueryValueKey(hKey,
			&ValueName,
			KeyValuePartialInformation,
			Buffer,
			dwDataSize,
			&dwDataSize);

	}

	if (!NT_SUCCESS(m_NtStatus)) {
		uint32 tmp = -1;
		RegType = &tmp;
		*RetBuffer = ref new Platform::Array<uint8>(NULL);
		return FALSE;
	}

	info = (KEY_VALUE_PARTIAL_INFORMATION *)Buffer;

	NtClose(hKey);

	*RegType = info->Type;

	*RetBuffer = ref new Platform::Array<uint8>(info->Data, info->DataLength);
	return TRUE;
}

BOOL Registry::ReadValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, RegistryType RegType, KEY_VALUE_PARTIAL_INFORMATION** retInfo)
{
	DWORD dwSize = 0;
	RegistryType dwType = RegistryType::None;
	int nSize = 0;

	// make sure it is the proper type
	dwType = GetValueInfo(Hive, Key, Name, nSize);
	if (dwType != RegType) {
		return FALSE;
	}

	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cName = (PWSTR)Name->Data();
	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);


	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}


	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	//
	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, KEY_READ, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	if (Name == L"(Default)") {
		Name = L"";
	}

	UNICODE_STRING ValueName;
	RtlInitUnicodeString(&ValueName, cName);

	//
	WCHAR infoBuffer[256];
	memset(infoBuffer, 0, 256);
	*retInfo = (KEY_VALUE_PARTIAL_INFORMATION *)infoBuffer;

	m_NtStatus = NtQueryValueKey(hKey,
		&ValueName,
		KeyValuePartialInformation,
		&infoBuffer,
		sizeof(infoBuffer),
		&dwSize);

	NtClose(hKey);
	if (!NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);
		RtlFreeUnicodeString(&ValueName);

		return FALSE;
	}

	RtlFreeUnicodeString(&uKey);
	RtlFreeUnicodeString(&ValueName);

	return TRUE;
}

BOOL Registry::ReadValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, uint32 RegType, KEY_VALUE_PARTIAL_INFORMATION** retInfo)
{
	DWORD dwSize = 0;
RegistryRT:ULONG dwType = 0;
	int nSize = 0;

	// make sure it is the proper type
	dwType = GetValueInfo2(Hive, Key, Name, nSize);
	if (dwType != (int32)RegType) {
		return FALSE;
	}

	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cName = (PWSTR)Name->Data();
	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);


	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}


	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	//
	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, KEY_READ, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	if (Name == L"(Default)") {
		Name = L"";
	}

	UNICODE_STRING ValueName;
	RtlInitUnicodeString(&ValueName, cName);

	//
	WCHAR infoBuffer[256];
	memset(infoBuffer, 0, 256);
	*retInfo = (KEY_VALUE_PARTIAL_INFORMATION *)infoBuffer;

	m_NtStatus = NtQueryValueKey(hKey,
		&ValueName,
		KeyValuePartialInformation,
		&infoBuffer,
		sizeof(infoBuffer),
		&dwSize);

	NtClose(hKey);
	if (!NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);
		RtlFreeUnicodeString(&ValueName);

		return FALSE;
	}

	RtlFreeUnicodeString(&uKey);
	RtlFreeUnicodeString(&ValueName);

	return TRUE;
}

RegistryType Registry::GetValueInfo(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, int nSize)
{

	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cName = (PWSTR)Name->Data();
	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	HANDLE hKey;

	ULONG ret = NtOpenKey(&hKey, GENERIC_READ, &ObjectAttributes);

	UNICODE_STRING ValueName;
	RtlInitUnicodeString(&ValueName, cName);

	BYTE *Buffer;
	DWORD dwDataSize = 0;

	KEY_VALUE_FULL_INFORMATION *info;

	NTSTATUS m_NtStatus = STATUS_SUCCESS;

	if (NtQueryValueKey(hKey, &ValueName, KeyValueFullInformation,
		NULL, 0, &dwDataSize) == STATUS_BUFFER_OVERFLOW)
	{
		do {
			Buffer = (BYTE*)HeapAlloc(GetProcessHeap(), 0, dwDataSize + 1024 + sizeof(WCHAR));
			if (!Buffer) {
				NtClose(hKey);
				return RegistryType::None;
			}

			m_NtStatus = NtQueryValueKey(hKey, &ValueName, KeyValueFullInformation,
				Buffer, dwDataSize, &dwDataSize);

		} while (m_NtStatus == STATUS_BUFFER_OVERFLOW);
	}
	else
	{
		Buffer = (BYTE*)HeapAlloc(GetProcessHeap(), 0, dwDataSize + 1024);
		if (!Buffer) {
			NtClose(hKey);
			return RegistryType::None;
		}

		m_NtStatus = NtQueryValueKey(hKey,
			&ValueName,
			KeyValueFullInformation,
			Buffer,
			dwDataSize,
			&dwDataSize);

	}

	info = (KEY_VALUE_FULL_INFORMATION *)Buffer;

	NtClose(hKey);

	int tmp = info->DataLength / 2;

	nSize = tmp;

	ULONG retval = info->Type;
	return static_cast<RegistryType>(retval);
}

unsigned int Registry::GetValueInfo2(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, int nSize)
{

	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cName = (PWSTR)Name->Data();
	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	HANDLE hKey;

	ULONG ret = NtOpenKey(&hKey, GENERIC_READ, &ObjectAttributes);

	UNICODE_STRING ValueName;
	RtlInitUnicodeString(&ValueName, cName);

	BYTE *Buffer;
	DWORD dwDataSize = 0;

	KEY_VALUE_FULL_INFORMATION *info;

	NTSTATUS m_NtStatus = STATUS_SUCCESS;

	if (NtQueryValueKey(hKey, &ValueName, KeyValueFullInformation,
		NULL, 0, &dwDataSize) == STATUS_BUFFER_OVERFLOW)
	{
		do {
			Buffer = (BYTE*)HeapAlloc(GetProcessHeap(), 0, dwDataSize + 1024 + sizeof(WCHAR));
			if (!Buffer) {
				NtClose(hKey);
				return -1;
			}

			m_NtStatus = NtQueryValueKey(hKey, &ValueName, KeyValueFullInformation,
				Buffer, dwDataSize, &dwDataSize);

		} while (m_NtStatus == STATUS_BUFFER_OVERFLOW);
	}
	else
	{
		Buffer = (BYTE*)HeapAlloc(GetProcessHeap(), 0, dwDataSize + 1024);
		if (!Buffer) {
			NtClose(hKey);
			return -1;
		}

		m_NtStatus = NtQueryValueKey(hKey,
			&ValueName,
			KeyValueFullInformation,
			Buffer,
			dwDataSize,
			&dwDataSize);

	}

	info = (KEY_VALUE_FULL_INFORMATION *)Buffer;

	NtClose(hKey);

	int tmp = info->DataLength / 2;

	nSize = tmp;

	ULONG retval = info->Type;
	return retval;
}

Platform::String^ Registry::GetRootPathFor(RegistryHive hRoot)
{
	Platform::String^ csRootPath = L"";
	if (hRoot == RegistryHive::HKEY_LOCAL_MACHINE) {
		csRootPath = L"\\Registry\\Machine";
	}
	else if (hRoot == RegistryHive::HKEY_CLASSES_ROOT) {
		csRootPath = L"\\Registry\\Machine\\SOFTWARE\\Classes";
	}
	else if (hRoot == RegistryHive::HKEY_CURRENT_CONFIG) {
		csRootPath = L"\\Registry\\Machine\\System\\CurrentControlSet\\Hardware Profiles\\Current";
	}
	else if (hRoot == RegistryHive::HKEY_USERS) {
		csRootPath = L"\\Registry\\User";
	}
	else if (hRoot == RegistryHive::HKEY_CURRENT_USER) {
		csRootPath = L"\\Registry\\User\\" + GetCurrentUserSID();
	}
	else if (hRoot == RegistryHive::HKEY_CURRENT_USER_LOCAL_SETTINGS) {
		csRootPath = L"\\Registry\\User\\" + GetCurrentUserSID() + "\\Software\\Classes\\Local Settings";
	}

	return csRootPath;
}

Platform::Boolean Registry::ValueExists(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cName = (PWSTR)Name->Data();
	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	//
	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, KEY_QUERY_VALUE, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	if (cName == L"(Default)") {
		cName = L"";
	}

	UNICODE_STRING ValueName;
	RtlInitUnicodeString(&ValueName, cName);

	if (IsKeyHidden(Hive, Key)) {
		ValueName.MaximumLength = ValueName.Length += 2;
	}

	WCHAR buffer[8192];
	DWORD dwSize;
	m_NtStatus = NtQueryValueKey(hKey,
		&ValueName,
		KeyValueFullInformation,
		buffer,
		sizeof(buffer),
		&dwSize);

	NtClose(hKey);
	if (!NT_SUCCESS(m_NtStatus)) {
		//Output(DisplayError(m_NtStatus));

		RtlFreeUnicodeString(&uKey);
		RtlFreeUnicodeString(&ValueName);

		return FALSE;
	}

	RtlFreeUnicodeString(&uKey);
	RtlFreeUnicodeString(&ValueName);

	return TRUE;
}

Platform::Boolean Registry::GetKeyLastWriteTime(RegistryHive Hive, Platform::String^ Key, int64 *LastWriteTime)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	//
	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, KEY_QUERY_VALUE, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	WCHAR buffer[256];
	KEY_BASIC_INFORMATION *info = (KEY_BASIC_INFORMATION *)buffer;

	DWORD dwResultLength;
	m_NtStatus = NtQueryKey(hKey,
		KeyBasicInformation,
		buffer,
		sizeof(buffer),
		&dwResultLength);

	if (!NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	LARGE_INTEGER time = info->LastWriteTime;

	*LastWriteTime = time.QuadPart;

	m_NtStatus = NtClose(hKey);
	if (!NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	RtlFreeUnicodeString(&uKey);

	return TRUE;
}

Platform::Boolean Registry::GetSubKeyList(RegistryHive Hive, Platform::String^ Key, Platform::Array<Platform::String^> ^*csaSubkeys)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	//
	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, KEY_ENUMERATE_SUB_KEYS, &ObjectAttributes);
	/*if (!NT_SUCCESS(m_NtStatus)) {
	return FALSE;
	}*/

	ULONG resultLength;
	CHAR szKeyInfo[1024];
	UINT i = 0;

	Platform::String^ csSubkey;

	std::vector<Platform::String^> Subkeys;

	// Scan for subkeys
	while ((m_NtStatus = NtEnumerateKey(hKey, i, KeyBasicInformation, szKeyInfo, sizeof(szKeyInfo), &resultLength)) == STATUS_SUCCESS)
	{
		PKEY_BASIC_INFORMATION tInfo = (PKEY_BASIC_INFORMATION)szKeyInfo;
		String ^curstr = ref new String(tInfo->Name, tInfo->NameLength / 2);
		Subkeys.push_back(curstr);
		i++;
	}

	*csaSubkeys = ref new Platform::Array<Platform::String^>(Subkeys.data(), Subkeys.size());

	m_NtStatus = NtClose(hKey);
	/*if (!NT_SUCCESS(m_NtStatus)) {
	return FALSE;
	}*/

	RtlFreeUnicodeString(&uKey);

	return TRUE;
}

Platform::Boolean Registry::GetValueList(RegistryHive Hive, Platform::String^ Key, Platform::Array<Platform::String^> ^*csaValues)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	//
	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, GENERIC_READ, &ObjectAttributes);
	/*if (!NT_SUCCESS(m_NtStatus)) {
	return FALSE;
	}*/

	ULONG resultLength;
	CHAR szValueInfo[1024];
	UINT i = 0;

	Platform::String^ csSubkey;

	std::vector<Platform::String^> Subkeys;

	NTSTATUS NtStatus;
	// Scan for subkeys
	while ((NtStatus = NtEnumerateValueKey(hKey, i, KeyValueBasicInformation, szValueInfo, sizeof(szValueInfo), &resultLength)) == STATUS_SUCCESS)
	{
		PKEY_VALUE_BASIC_INFORMATION tInfo = (PKEY_VALUE_BASIC_INFORMATION)szValueInfo;
		String ^curstr = ref new String(tInfo->Name, tInfo->NameLength / 2);
		Subkeys.push_back(curstr);
		i++;
	}

	*csaValues = ref new Platform::Array<Platform::String^>(Subkeys.data(), Subkeys.size());

	NtClose(hKey);
	/*if (!NT_SUCCESS(m_NtStatus)) {
	return FALSE;
	}*/

	RtlFreeUnicodeString(&uKey);

	return TRUE;
}

Platform::String^ Registry::GetCurrentUserSID() {

	BOOL         fSuccess = FALSE;
	HANDLE       hToken = NULL;
	PTOKEN_USER  ptiUser = NULL;
	DWORD        cbti = 0;
	SID_NAME_USE snu;
	UNICODE_STRING StringSid;
	Platform::String^ UserSid;

	// Get the calling thread's access token.
	if (!OpenThreadToken(GetCurrentThread(), TOKEN_QUERY, TRUE,
		&hToken)) {

		if (GetLastError() != ERROR_NO_TOKEN)
			throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

		// Retry against process token if no thread token exists.
		if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY,
			&hToken))
			throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));
	}

	// Obtain the size of the user information in the token.
	if (GetTokenInformation(hToken, TokenUser, NULL, 0, &cbti)) {

		// Call should have failed due to zero-length buffer.
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	}
	else {

		// Call should have failed due to zero-length buffer.
		if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
			throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));
	}

	// Allocate buffer for user information in the token.
	ptiUser = (PTOKEN_USER)HeapAlloc(GetProcessHeap(), 0, cbti);
	if (!ptiUser)
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));

	// Retrieve the user information from the token.
	if (!GetTokenInformation(hToken, TokenUser, ptiUser, cbti, &cbti))
		throw ref new Platform::COMException(HRESULT_FROM_WIN32(GetLastError()));


	auto status = RtlConvertSidToUnicodeString(&StringSid, ptiUser->User.Sid, TRUE);
	if (status != 0) {
		throw ref new Platform::COMException(HRESULT_FROM_NT(status));
	}

	UserSid = ref new Platform::String(StringSid.Buffer, StringSid.Length / 2);

	fSuccess = TRUE;

	// Free resources.
	if (hToken)
		CloseHandle(hToken);

	if (ptiUser)
		HeapFree(GetProcessHeap(), 0, ptiUser);

	return UserSid;
}

Platform::Boolean Registry::WriteValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, PVOID pValue, RegistryRT::ULONG ulValueLength, RegistryType dwRegType)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cName = (PWSTR)Name->Data();
	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	//
	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, KEY_SET_VALUE, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {

		//RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	if (cName == L"(Default)") {
		cName = L"";
	}

	UNICODE_STRING ValueName;
	RtlInitUnicodeString(&ValueName, cName);

	//
	// I do this (new and delete []) because I was getting
	// a lot of extra characters in the data (in the registry).
	//
	UCHAR *puc = new UCHAR[ulValueLength];
	memset(puc, 0, ulValueLength);
	memcpy(puc, pValue, ulValueLength);

	m_NtStatus = NtSetValueKey(hKey,
		&ValueName,
		0,
		(DWORD)dwRegType,		// i.e. REG_BINARY
		puc,
		ulValueLength);

	// Clean up...
	delete[] puc;

	if (!NT_SUCCESS(m_NtStatus)) {
		NtClose(hKey);

		//RtlFreeUnicodeString(&uKey);
		//RtlFreeUnicodeString(&ValueName);

		return FALSE;
	}

	NtFlushKey(hKey);

	NtClose(hKey);

	//RtlFreeUnicodeString(&uKey);
	//RtlFreeUnicodeString(&ValueName);

	return TRUE;
}

Platform::Boolean Registry::WriteValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, PVOID pValue, RegistryRT::ULONG ulValueLength, DWORD dwRegType)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cName = (PWSTR)Name->Data();
	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	//
	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, KEY_SET_VALUE, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {

		//RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	if (cName == L"(Default)") {
		cName = L"";
	}

	UNICODE_STRING ValueName;
	RtlInitUnicodeString(&ValueName, cName);

	//
	// I do this (new and delete []) because I was getting
	// a lot of extra characters in the data (in the registry).
	//
	UCHAR *puc = new UCHAR[ulValueLength];
	memset(puc, 0, ulValueLength);
	memcpy(puc, pValue, ulValueLength);

	m_NtStatus = NtSetValueKey(hKey,
		&ValueName,
		0,
		dwRegType,		// i.e. REG_BINARY
		puc,
		ulValueLength);

	// Clean up...
	delete[] puc;

	if (!NT_SUCCESS(m_NtStatus)) {
		NtClose(hKey);

		//RtlFreeUnicodeString(&uKey);
		//RtlFreeUnicodeString(&ValueName);

		return FALSE;
	}

	NtFlushKey(hKey);

	NtClose(hKey);

	//RtlFreeUnicodeString(&uKey);
	//RtlFreeUnicodeString(&ValueName);

	return TRUE;
}

Platform::Boolean Registry::WriteValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, const Platform::Array<uint8>^ csaValue, RegistryType type)
{
	return WriteValue(Hive, Key, Name, csaValue->Data, (ULONG)csaValue->Length, type);
}

Platform::Boolean Registry::WriteValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name, const Platform::Array<uint8>^ csaValue, uint32 type)
{
	return WriteValue(Hive, Key, Name, csaValue->Data, (ULONG)csaValue->Length, type);
}

Platform::Boolean Registry::RenameKey(RegistryHive Hive, Platform::String^ Key, Platform::String^ csNewKeyName)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, KEY_CREATE_SUB_KEY, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	PWSTR cName = (PWSTR)csNewKeyName->Data();
	UNICODE_STRING asNewKey;
	RtlInitUnicodeString(&asNewKey, cName);

	UNICODE_STRING ReplacementName;
	RtlZeroMemory(&ReplacementName, sizeof(ReplacementName));

	if (IsKeyHidden(Hive, Key)) {
		ReplacementName.MaximumLength = ReplacementName.Length += 2;
	}

	m_NtStatus = NtRenameKey(hKey, &ReplacementName);
	if (!NT_SUCCESS(m_NtStatus)) {
		NtClose(hKey);

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	RtlFreeUnicodeString(&uKey);

	return TRUE;
}

Platform::Boolean Registry::DeleteKey(RegistryHive Hive, Platform::String^ Key)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, DELETE, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	m_NtStatus = NtDeleteKey(hKey);
	if (!NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	RtlFreeUnicodeString(&uKey);

	return TRUE;
}

Platform::Boolean Registry::DeleteKeysRecursive(RegistryHive Hive, Platform::String^ Key)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	BOOL bHidden = FALSE;
	if (IsKeyHidden(Hive, Key)) {
		bHidden = TRUE;
	}

	if (bHidden) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	// Init the Obj Attirbutes...
	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	// Let's do it
	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, DELETE, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus))
	{
		// if we are here, somethings wrong??

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	ULONG resultLength;
	CHAR szSubkeyInfo[1024];

	Platform::String^ csSubkey, ^csNewSubkey;

	// Had trouble with
	// Key was opened OK, now let's scan for subkeys
	while ((m_NtStatus = NtEnumerateKey(hKey, 0, KeyBasicInformation, szSubkeyInfo, sizeof(szSubkeyInfo), &resultLength)) == STATUS_SUCCESS)
	{
		// Copy the Data into the structure so we can use it
		PKEY_BASIC_INFORMATION tInfo = (PKEY_BASIC_INFORMATION)szSubkeyInfo;
		// put the subkey name into a variable
		csSubkey = ref new Platform::String(tInfo->Name);
		// now create a new subkey that we need to check

		csNewSubkey = Key + L"\\" + ref new String(csSubkey->Data(), tInfo->NameLength / 2);

		// Now, search for more keys 
		if (!DeleteKeysRecursive(Hive, csNewSubkey)) {
			break; // Something failed...break out of for loop
		}
	}

	// Delete the current key
	m_NtStatus = NtDeleteKey(hKey);
	if (!NT_SUCCESS(m_NtStatus)) {
		// Couldn't delete it, so we 
		// have to close it correctly...
		NtClose(hKey);

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}
	// All went OK

	RtlFreeUnicodeString(&uKey);

	return TRUE;
}

Platform::Boolean Registry::CreateKey(RegistryHive Hive, Platform::String^ Key)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	// Obvious
	HANDLE hKey = NULL;
	//
	DWORD m_dwDisposition = 0;
	// if the key doesn't exist, create it
	NTSTATUS m_NtStatus = NtCreateKey(&hKey,
		KEY_CREATE_SUB_KEY,
		&ObjectAttributes,
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		&m_dwDisposition);
	//
	if (!NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}
	// Obvious
	if (hKey) {
		NtClose(hKey);
	}

	RtlFreeUnicodeString(&uKey);

	return TRUE;
}

Platform::Boolean Registry::DeleteValue(RegistryHive Hive, Platform::String^ Key, Platform::String^ Name)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cName = (PWSTR)Name->Data();
	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	//
	HANDLE hKey = NULL;
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, KEY_SET_VALUE, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);

		return FALSE;
	}

	if (cName == L"(Default)") {
		cName = L"";
	}

	UNICODE_STRING ValueName;
	RtlInitUnicodeString(&ValueName, cName);

	m_NtStatus = NtDeleteValueKey(hKey, &ValueName);

	NtClose(hKey);
	if (NT_SUCCESS(m_NtStatus)) {

		RtlFreeUnicodeString(&uKey);
		RtlFreeUnicodeString(&ValueName);

		return TRUE;
	}

	RtlFreeUnicodeString(&uKey);
	RtlFreeUnicodeString(&ValueName);

	return FALSE;
}

unsigned int Registry::GetKeyStatus(RegistryHive Hive, Platform::String^ Key)
{
	String^ hivepath = GetRootPathFor(Hive);

	String^ fullpath = hivepath + "\\" + Key;

	if (Key == L"") {
		fullpath = hivepath;
	}

	PWSTR cKey = (PWSTR)fullpath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	if (IsKeyHidden(Hive, Key)) {
		uKey.MaximumLength = uKey.Length += 2;
	}

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	// Obvious
	HANDLE hKey = NULL;
	// otherwise, open the key without creating it
	NTSTATUS m_NtStatus = NtOpenKey(&hKey, KEY_READ, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {
		//Output(DisplayError(m_NtStatus));

		RtlFreeUnicodeString(&uKey);

		return m_NtStatus;
	}
	// Obvious
	if (hKey) {
		NtClose(hKey);
	}

	RtlFreeUnicodeString(&uKey);

	return m_NtStatus;
}

Platform::Boolean Registry::LoadHive(Platform::String^ HiveFile, Platform::String^ MountName, Platform::Boolean InUser)
{
	Platform::String^ csRootPath = L"";

	if (!InUser)
	{
		csRootPath = L"\\Registry\\Machine\\" + MountName;
	}
	else
	{
		csRootPath = L"\\Registry\\User\\" + MountName;
	}

	Platform::String^ FullPath = L"\\??\\" + HiveFile;

	PWSTR cFullPath = (PWSTR)FullPath->Data();
	PWSTR cKey = (PWSTR)csRootPath->Data();

	UNICODE_STRING uHiveFile;
	RtlInitUnicodeString(&uHiveFile, cFullPath);

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, &uHiveFile, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	OBJECT_ATTRIBUTES ObjectAttributes2;
	InitializeObjectAttributes(&ObjectAttributes2, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	NTSTATUS m_NtStatus = NtLoadKey(&ObjectAttributes2, &ObjectAttributes);
	if (!NT_SUCCESS(m_NtStatus)) {
		return false;
	}

	return true;
}

Platform::Boolean Registry::UnloadHive(Platform::String^ KeyPath, Platform::Boolean InUser)
{
	/*NTSTATUS m_NtStatus = EnablePrivilege(SE_RESTORE_NAME, TRUE);
	if (!NT_SUCCESS(m_NtStatus)) {
		return false;
	}*/

	Platform::String^ csRootPath = L"";

	if (!InUser)
	{
		csRootPath = L"\\Registry\\Machine\\" + KeyPath;
	}
	else
	{
		csRootPath = L"\\Registry\\User\\" + KeyPath;
	}


	PWSTR cKey = (PWSTR)csRootPath->Data();

	UNICODE_STRING uKey;
	RtlInitUnicodeString(&uKey, cKey);

	OBJECT_ATTRIBUTES ObjectAttributes2;
	InitializeObjectAttributes(&ObjectAttributes2, &uKey, OBJ_CASE_INSENSITIVE, 0x00000000, NULL);

	NTSTATUS m_NtStatus = NtUnloadKey(&ObjectAttributes2);
	if (!NT_SUCCESS(m_NtStatus)) {
		//m_NtStatus = EnablePrivilege(SE_RESTORE_NAME, FALSE);
		return false;
	}

	//m_NtStatus = EnablePrivilege(SE_RESTORE_NAME, FALSE);
	return true;
}