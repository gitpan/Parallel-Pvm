use ExtUtils::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    'LD' => 'ld',
    'NAME'	=> 'Parallel::Pvm',
    'VERSION_FROM' => 'Pvm.pm', # finds $VERSION
    'DEFINE'	=> '',     # e.g., '-DHAVE_SOMETHING' 
    'INC'	=> '-I$(PVM_ROOT)/include',     # e.g., '-I/usr/include/other' 
    'MYEXTLIB' => '$(PVM_ROOT)/lib/$(PVM_ARCH)/libpvm3.a',
# for Solaris you may have to uncomment the line below
#    'LIBS'	=> "-lsocket -lnsl",
    'dist' => {COMPRESS => "gzip", SUFFIX => "gz"},
);
