# Microsoft Developer Studio Project File - Name="Cpp_simple" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Cpp_simple - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE
!MESSAGE NMAKE /f "Cpp_simple.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "Cpp_simple.mak" CFG="Cpp_simple - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "Cpp_simple - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Cpp_simple - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe


!IF  "$(CFG)" == "Cpp_simple - Win32 Release"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O1 /I "..\..\..\Mappings\Cpp_simple" /I "..\..\..\include" /I "$(STLSOFT_INCLUDE)" /I "$(STLSOFT_INCLUDE)\inprogress" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 openrj.vc6.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /version:1.0 /subsystem:console /machine:I386 /libpath:"..\..\..\lib"

!ELSEIF  "$(CFG)" == "Cpp_simple - Win32 Debug"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /GX /Zi /Od /I "..\..\..\Mappings\Cpp_simple" /I "..\..\..\include" /I "$(STLSOFT_INCLUDE)" /I "$(STLSOFT_INCLUDE)\inprogress" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 openrj.vc6.debug.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /version:1.0 /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"..\..\..\lib"

!ENDIF

# Begin Target

# Name "Cpp_simple - Win32 Release"
# Name "Cpp_simple - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\Cpp_simple.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "STLSoft Header Files"

# PROP Default_Filter ""
# Begin Group "STLSoft"

# PROP Default_Filter ""
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\allocator_base.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\auto_buffer.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\char_traits.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\constraints.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\iterator.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\meta.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\new_allocator.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\operator_bool.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\operator_bool_adaptor.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\sap_cast.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\sign_traits.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\simple_algorithms.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\size_traits.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_allocator_base.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_auto_buffer.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_cccap_msvc.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_char_traits.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_constraints.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_iterator.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_meta.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_new_allocator.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_operator_bool.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_sap_cast.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_shim_string.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_sign_traits.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_simple_algorithms.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_size_traits.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_string_access.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft_type_traits.h
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\string_access.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\string_access_fwd.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\string_view.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\type_traits.hpp
# End Source File
# Begin Source File

SOURCE=$(STLSOFT_INCLUDE)/stlsoft\meta\yesno.hpp
# End Source File
# End Group
# End Group
# Begin Group "Open-RJ Header Files"

# PROP Default_Filter ""
# Begin Group "API"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(OPENRJ_ROOT)\include\openrj\openrj.h"
# End Source File
# Begin Source File

SOURCE="$(OPENRJ_ROOT)\include\openrj\openrj_assert.h"
# End Source File
# End Group
# Begin Group "C++ Mapping"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(OPENRJ_ROOT)\include\openrj\cpp\database.hpp"
# End Source File
# Begin Source File

SOURCE="$(OPENRJ_ROOT)\include\openrj\cpp\databasebase.hpp"
# End Source File
# Begin Source File

SOURCE="$(OPENRJ_ROOT)\include\openrj\cpp\field.hpp"
# End Source File
# Begin Source File

SOURCE="$(OPENRJ_ROOT)\include\openrj\cpp\filedatabase.hpp"
# End Source File
# Begin Source File

SOURCE="$(OPENRJ_ROOT)\include\openrj\cpp\memorydatabase.hpp"
# End Source File
# Begin Source File

SOURCE="$(OPENRJ_ROOT)\include\openrj\cpp\openrj.hpp"
# End Source File
# Begin Source File

SOURCE="$(OPENRJ_ROOT)\include\openrj\cpp\record.hpp"
# End Source File
# End Group
# End Group
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
