use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile
(
    'NAME'	=> 'Parallel::Pvm',
    'VERSION_FROM' => 'Pvm.pm', # finds $VERSION
    'LIBS'	=> [''],   # e.g., '-lm' 
    'DEFINE'	=> '',     # e.g., '-DHAVE_SOMETHING' 
    'INC'	=> '',     # e.g., '-I/usr/include/other' 
    'DEFINE'	=> '',     # e.g., '-DHAVE_SOMETHING' 
    'INC'	=> '-I$(PVM_ROOT)/include', 
    'MYEXTLIB'  => '$(PVM_ROOT)/lib/$(PVM_ARCH)/libpvm3.a',
# for Solaris you may have to uncomment the line below
#    'LIBS'	=> "-lsocket -lnsl",
    'dist' => {COMPRESS => "gzip", SUFFIX => "gz"},
);
