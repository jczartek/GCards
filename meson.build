project('gcards', 'c',
  licencse: 'GPL+3',
  version: '0.1.0',
  default_options: [
    'c_std=gnu11',
    'warning_level=2'
  ]
)

cc = meson.get_compiler('c')
project_c_args = [
  '-Wcast-align',
  '-Wdeclaration-after-statement',
  ['-Werror=format-security', '-Werror=format=2'],
  '-Wformat-nonliteral',
  '-Wformat-security',
  '-Wmissing-include-dirs',
  '-Wnested-externs',
  '-Wno-missing-field-initializers',
  '-Wno-sign-compare',
  '-Wno-strict-aliasing',
  '-Wno-uninitialized',
  '-Wno-unused-parameter',
  '-Wpointer-arith',
  '-Wredundant-decls',
  '-Wshadow',
  '-Wswitch-default',
  '-Wswitch-enum',
  '-Wundef'
]
global_c_args = []

foreach arg: project_c_args
  if cc.has_multi_arguments(arg)
    global_c_args += arg
  endif
endforeach
add_project_arguments(
  global_c_args,
  language: 'c'
)

libgtk_dep = dependency('gtk+-3.0', version: '>= 3.22.1')
libcluter_dep = dependency('clutter-1.0', version: '>= 1.22.0')
libclutergtk_dep = dependency('clutter-gtk-1.0', version: '>= 1.6.0')

gnome = import('gnome')

subdir('src')
