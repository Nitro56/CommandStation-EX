# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

import os
import subprocess
import sphinx.builders.html

# Doxygen
subprocess.call('doxygen DoxyfileEXRAIL', shell=True)

# Get current version/branch
try:
    current_branch = subprocess.check_output(['git', 'rev-parse', '--abbrev-ref', 'HEAD']).decode('utf-8').strip()
except Exception as error:
    current_branch = 'unknown'

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'EXRAIL Language'
copyright = '2025 - Peter Cole'
author = 'Peter Cole'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
  'sphinx_sitemap',
  'sphinxcontrib.spelling',
  'sphinx_rtd_dark_mode',
  'breathe'
]

autosectionlabel_prefix_document = True

# Don't make dark mode the user default
default_dark_mode = False

spelling_lang = 'en_UK'
tokenizer_lang = 'en_UK'
spelling_word_list_filename = ['spelling_wordlist.txt']

templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

highlight_language = 'c++'

numfig = True

numfig_format = {'figure': 'Figure %s'}

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']

html_logo = "./_static/images/product-logo-ex-rail.png"

html_favicon = "./_static/images/favicon.ico"

html_theme_options = {
    'style_nav_header_background': 'white',
    'logo_only': True,
    # Toc options
    'includehidden': True,
    'titles_only': False,
    # 'titles_only': True,
    'collapse_navigation': False,
    # 'navigation_depth': 3,
    'navigation_depth': 1,
    'analytics_id': 'G-L5X0KNBF0W',
}

html_context = {
    'display_github': True,
    'github_user': 'DCC-EX',
    'github_repo': 'CommandStation-EX',
    'github_version': 'sphinx/docs/',
}

html_css_files = [
    'css/dccex_theme.css',
    'css/sphinx_design_overrides.css',
]

baseurl_prefix = 'https://dcc-ex.com/CommandStation-EX/'

# Change output directory depending on branch
if current_branch in ['master-exraildoc', 'master-exraildocdev']:
    # For versioning
    html_baseurl = f"{baseurl_prefix}{current_branch}/"
    html_extra_path = ['_build']
    builddir = os.path.join('_build', current_branch)
else:
    # Main landing page
    html_baseurl = baseurl_prefix
    builddir = '_build'

# Override default build directory
sphinx.builders.html.get_outfilename = lambda self, pagename: os.path.join(builddir, pagename + '.html')

# Sphinx sitemap
html_extra_path = [
  'robots.txt',
]

# -- Breathe configuration -------------------------------------------------

breathe_projects = {
  "EXRAIL Language": "_build/xml/"
}
breathe_default_project = "EXRAIL Language"
breathe_default_members = ()
