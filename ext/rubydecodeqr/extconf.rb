require 'mkmf'

have_library 'stdc++'
extension_name = 'rubydecodeqr/rubydecodeqr'
dir_config extension_name

$CFLAGS << " -x c++"
$CPPFLAGS << " -I/usr/include/opencv"
$LOCAL_LIBS << " -ldecodeqr -lopencv_core -lopencv_highgui"

create_makefile extension_name