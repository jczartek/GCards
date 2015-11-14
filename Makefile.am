ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

SUBDIRS = tools src

MAINTAINERCLEANFILES =                                                         \
		$(GITIGNORE_MAINTAINERCLEANFILES_TOPLEVEL)                     \
		$(GITIGNORE_MAINTAINERCLEANFILES_MAKEFILE_IN)                  \
		$(GITIGNORE_MAINTAINERCLEANFILES_M4_LIBTOOL)                   \
		$(NULL)
DISTCLEANFILES = INSTALL configure aclocal.m4

-include $(top_srcdir)/git.mk
