#
# Makefile.am for liby2util/src/include/y2util
#

pkgincludedir = $(includedir)/y2util

# these go to $(pkgincludedir)

pkginclude_HEADERS =		\
	ExternalDataSource.h \
	ExternalProgram.h \
	MemUsage.h \
	PathInfo.h \
	Pathname.h \
	Process.h \
	Rep.h \
	RepDef.h \
	TreeItem.h \
	Ustring.h \
	Y2SLog.h \
	miniini.h \
	stringutil.h \
	y2log.h \
	y2changes.h


#<INSTALL-HEADER-TARGET>

# Automatically inserted by insert_install_target
# DO NOT REMOVE THE TAGS!

# Install header files only if different to version already installed -
# prevent unnecessary installations to keep make dependency changes
# and thus rebuilds for dependent packages as low as possible.

install-pkgincludeHEADERS: $(pkginclude_HEADERS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(pkgincludedir)
	@list='$(pkginclude_HEADERS)';							\
	for p in $$list; do								\
		if test -f "$$p"; then d= ; else d="$(srcdir)/"; fi;			\
		if ! cmp -s $$d$$p $(DESTDIR)$(pkgincludedir)/$$p; then			\
			echo " $(INSTALL_DATA) $$d$$p $(DESTDIR)$(pkgincludedir)/$$p";	\
			$(INSTALL_DATA) $$d$$p $(DESTDIR)$(pkgincludedir)/$$p;		\
		fi									\
	done

#</INSTALL-HEADER-TARGET>
