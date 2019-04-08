AC_PREREQ(2.52)

AM_CONFIG_HEADER(config.h)
AC_INIT([libgtkhtml], [0.2.10], [wdlkmpx@github])
AM_INIT_AUTOMAKE([-Wall -Wno-portability foreign])

AC_CONFIG_MACRO_DIRS([m4])
AC_PROG_CC
AC_ISC_POSIX
AC_HEADER_STDC
AM_PROG_LIBTOOL

dnl ALL_LINGUAS="hi"
dnl AM_GNU_GETTEXT

AC_ARG_ENABLE(more-warnings,
       [  --enable-more-warnings  maximum compiler warnings],
       set_more_warnings="$enableval",set_more_warnings=no)

if test "$GCC" = "yes" -a "$set_more_warnings" != "no"; then
       echo "enable compile warnings = $set_more_warnings"
       CFLAGS="-Wall -Wno-uninitialized \
               -Wchar-subscripts -Wmissing-declarations -Wmissing-prototypes \
               -Wnested-externs -Wpointer-arith \
               -Wno-sign-compare -Wsign-promo -Werror \
	       $CFLAGS"
fi

AC_SUBST(CFLAGS)
AC_SUBST(LDFLAGS)


PKG_CHECK_MODULES(GTKHTML2, gtk+-2.0 >= 2.4.0 libxml-2.0 >= 2.4.16)


AC_ARG_ENABLE(accessibility,
              [  --enable-accessibility  enable accessibility support (needs gail) [default=yes]], ,
              enable_accessibility=yes)

if test x$enable_accessibility = xyes; then
  PKG_CHECK_MODULES(GAILUTIL, gail >= 1.8, ,
	            AC_MSG_ERROR([
*** gail is needed for accessibility. Either install gail or turn off 
*** accessibility support using the --disable-accessibility option.]))

  AC_DEFINE(ENABLE_ACCESSIBILITY, 1,
	    [Define to 1 to enable accessibility support.])
else
  AC_MSG_WARN([*** GtkHtml2 will be built without accessibility support.])
fi

AM_CONDITIONAL(ENABLE_ACCESSIBILITY, test x$enable_accessibility = xyes)


PKG_CHECK_MODULES(GNOME_VFS, gnome-vfs-2.0 >= 1.9.8, have_vfs=true,
	          AC_MSG_WARN([*** test apps will be built without GNOME VFS support.]) 
                  have_vfs=false)

AM_CONDITIONAL(HAVE_GNOME_VFS, test x$have_vfs = xtrue)


AC_SUBST(GTKHTML2_CFLAGS)
AC_SUBST(GTKHTML2_LIBS)
AC_SUBST(GNOME_VFS_CFLAGS)
AC_SUBST(GNOME_VFS_LIBS)
AC_SUBST(GAILUTIL_CFLAGS)
AC_SUBST(GAILUTIL_LIBS)
AC_SUBST(A11Y)

AC_OUTPUT([
Makefile
libgtkhtml/Makefile
libgtkhtml/css/Makefile
libgtkhtml/document/Makefile
libgtkhtml/dom/Makefile
libgtkhtml/dom/core/Makefile
libgtkhtml/dom/html/Makefile
libgtkhtml/dom/events/Makefile
libgtkhtml/dom/views/Makefile
libgtkhtml/dom/traversal/Makefile
libgtkhtml/graphics/Makefile
libgtkhtml/layout/Makefile
libgtkhtml/layout/html/Makefile
libgtkhtml/util/Makefile
libgtkhtml/view/Makefile
libgtkhtml/a11y/Makefile
tests/Makefile
tests/samples/Makefile
libgtkhtml-2.0.pc
])

