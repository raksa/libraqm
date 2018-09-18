project('raqm', 'c', version : '0.7.0', default_options : 'c_std=c99')

cc = meson.get_compiler('c')
pkg = import('pkgconfig')

freetype = dependency('freetype2', version : '>= 12.0.6')
harfbuzz = dependency('harfbuzz')
fribidi = dependency('fribidi')
deps = [freetype, harfbuzz, fribidi]

conf = configuration_data()
conf.set('VERSION', meson.project_version())
if cc.has_function('hb_ft_font_create_referenced', dependencies : harfbuzz)
  conf.set('HAVE_HB_FT_FONT_CREATE_REFERENCED', 1)
endif
if cc.has_function('hb_ft_font_set_load_flags', dependencies : harfbuzz)
  conf.set('HAVE_HB_FT_FONT_SET_LOAD_FLAGS', 1)
endif
configure_file(output : 'config.h', configuration : conf)

libraqm = library(
  'raqm',
  'src/raqm.c',
  'src/raqm.h',
  dependencies : deps,
  c_args : ['-DHAVE_CONFIG_H'],
  install : true,
)

libraqm_test = library(
  'raqm-test',
  'src/raqm.c',
  'src/raqm.h',
  dependencies : deps,
  c_args : ['-DRAQM_TESTING', '-DHAVE_CONFIG_H'],
  install : false,
)

pkg.generate(
  filebase : meson.project_name(),
  version : meson.project_version(),
  name : meson.project_name(),
  description : 'A library for complex text layout',
  url : 'https://github.com/HOST-Oman/libraqm',
  libraries : libraqm,
)

subdir('tests')
if get_option('docs')
  subdir('docs')
endif
