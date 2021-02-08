# RPM Spec file
# Martin Iturbide

Name:           KillFold
Version:        1.0
Release:        1%{?dist}
Summary:        Utility which closes all open folders.
Group:          Utility
License:        Public Domain
          

Vendor:         Dave Looney

Obsoletes:	KillFold < %{version}-%{release}
Provides:	KillFold = %{version}-%{release}
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
BuildArch:	i686


%description
KILLFOLD closes all open Desktop Folders (except the Desktop itself !) without affecting running program.

%prep
# we have no source, so nothing here

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/@unixroot/usr/bin
mkdir -p $RPM_BUILD_ROOT/@unixroot/usr/share/doc/%{name}
cp -p KILLFOLD.EXE $RPM_BUILD_ROOT/@unixroot/usr/bin
cp -p KILLFOLD.TXT $RPM_BUILD_ROOT/@unixroot/usr/share/doc/%{name}

%files
%{_bindir}/KILLFOLD.EXE
%doc KILLFOLD.TXT

%changelog
# let's skip this for now

%post
if [ "$1" -ge 1 ]; then # (upon update)
    %wps_object_delete_all
fi
%wps_object_create_begin
KILLFLD_EXE:WPProgram|Close All Folders|<WP_DESKTOP>|EXENAME=((%{_bindir}/KILLFOLD.EXE));MINIMIZED=YES;|R
%wps_object_create_end


%postun
if [ "$1" -eq 0 ]; then # (upon removal)
    %wps_object_delete_all
fi
