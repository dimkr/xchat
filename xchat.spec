Summary: Graphical IRC (chat) client
Name: xchat
Version: 1.8.9
Release: 0
Epoch: 1
Group: Applications/Internet
License: GPL
URL: http://xchat.org
Source: http://xchat.org/files/source/1.8/xchat-%{version}.tar.bz2
Buildroot: %{_tmppath}/%{name}-%{version}-root

%description
A GUI IRC client with DCC, plugin, Perl and Python scripting
capability, mIRC color, shaded transparency, tabbed channels
and more.

%prep
%setup -q

%build
%configure --disable-textfe --enable-openssl --disable-gdk-pixbuf --disable-python
make

%install
rm -rf $RPM_BUILD_ROOT
%makeinstall
mkdir -p $RPM_BUILD_ROOT%{_sysconfdir}/X11/applnk/Internet $RPM_BUILD_ROOT%{_datadir}/pixmaps

%find_lang %name

%files -f %{name}.lang
%defattr(-,root,root)
%doc README ChangeLog FAQ COPYING
%{_bindir}/xchat
%{_sysconfdir}/X11/applnk/Internet/xchat.desktop
%{_datadir}/pixmaps/xchat.png

%clean
rm -rf $RPM_BUILD_ROOT
