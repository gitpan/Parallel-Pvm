inherit perl-module

DESCRIPTION="Perl interface to the PVM parallel processing environment."
SRC_URI="mirror://cpan/authors/id/M/MS/MSCHILLI/${P}.tar.gz"	# TODO
HOMEPAGE="http://TODO.sourceforge.net/"	# TODO

SLOT="0"
LICENSE="|| ( Artistic GPL-2 )"
KEYWORDS="~x86 ~amd64 ~sparc ~ppc"
IUSE=""
DEPEND=">=dev-lang/perl-5.8.5 
        >=sys-cluster/pvm-3.4.4-r1"
