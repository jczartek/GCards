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

bin_PROGRAMS = gcards

gcards_SOURCES =                                                               \
		gc-main.c                                                      \
		gc-app.c                                                       \
		gc-window.c                                                    \
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
-include $(top_srcdir)/git.mk
