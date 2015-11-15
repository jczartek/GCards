gcards_resource_files = $(shell $(GLIB_COMPILE_RESOURCES) --sourcedir=$(srcdir) --generate-dependencies $(srcdir)/gcards.gresource.xml)
gc-resource.c: gcards.gresource.xml $(gcards_resource_files)
	$(GLIB_COMPILE_RESOURCES) --target=$@ --sourcedir=$(srcdir) --generate-source --c-name gc $(srcdir)/gcards.gresource.xml
gc-resource.h: gcards.gresource.xml $(gcards_resource_files)
	$(GLIB_COMPILE_RESOURCES) --target=$@ --sourcedir=$(srcdir) --generate-header --c-name gc $(srcdir)/gcards.gresource.xml

gcards_common_cppflags =                                                       \
		-I$(srcdir)                                                    \
		-I$(srcdir)/src                                                \
		$(CPPFLAGS)                                                    \
		$(NULL)

gcards_common_cflags =                                                         \
		$(CFLAGS)                                                      \
		$(GCARDS_CFLAGS)                                               \
		-pipe                                                          \
		-std=c99                                                       \
		$(NULL)

gcards_common_ldflags =                                                        \
		-export-dynamic                                                \
		$(LDFLAGS)                                                     \
		$(NULL)

BUILT_SOURCES =                                                                \
                gc-resource.h                                                  \
                gc-resource.c                                                  \
                $(NULL)

EXTRA_DIST =                                                                   \
                $(gcards_resource_files)                                       \
                $(NULL)

bin_PROGRAMS = gcards

gcards_SOURCES =                                                               \
		gc-main.c                                                      \
		gc-app.c                                                       \
		gc-greeter-window.c                                            \
		gc-session-window.c                                            \
		$(NULL)

gcards_CPPFLAGS =                                                              \
		$(gcards_common_cppflags)                                      \
		$(NULL)

gcards_CFLAGS =                                                                \
		$(gcards_common_cflags)                                        \
		$(NULL)

gcards_LDFLAGS =                                                               \
		$(gcards_common_ldflags)                                       \
		$(NULL)

gcards_LDADD =                                                                 \
		$(GCARDS_LIBS)                                                 \
		$(NULL)


DISTCLEANFILES = Makefile config.h config.h.in~ stamp-h1
DISTCLEANFILES += gc-resource.h gc-resource.c

-include $(top_srcdir)/git.mk
