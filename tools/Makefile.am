$(srcdir)/resurces/ui/gcards-greeter-window.ui: gcards-greeter-window-builder.rb
	echo "Create ui file: gcards-greeter-window.ui"
	$(top_srcdir)/tools/gcards-greeter-window-builder.rb
	echo "Create ui file: gcards-session-window.ui"
	$(top_srcdir)/tools/gcards-session-window-builder.rb

all: $(srcdir)/resurces/ui/gcards-greeter-window.ui

-include $(top_srcdir)/git.mk
