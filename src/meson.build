gc_resources = gnome.compile_resources('gc-resource',
  'gcards.gresource.xml',
  c_name: 'gc'
)

headers = [
  'gc-app.h',
  'gc-card.h',
  'gc-greeter-window.h',
  'gc-session-window.h'
]

sources = gc_resources + headers + [
  'gc-app.c',
  'gc-card.c',
  'gc-greeter-window.c',
  'gc-main.c',
  'gc-session-window.c'
]

executable('gcards', sources,
  gui_app: true,
  install: false,
  dependencies: [libgtk_dep, libcluter_dep, libclutergtk_dep]
)
