#
# Makefile.am for core/agent-system/testsuite
#

SUBDIRS = config lib ag_system.test tests

CLEANFILES = $(wildcard tmp.out.* tmp.err.* tmp.write.* *.sum *.log)

AM_CXXFLAGS = -DY2LOG=\"agent-system\"

PACKAGE = ag_system
AUTOMAKE_OPTIONS = dejagnu
export Y2DISABLELANGUAGEPLUGINS = 1

AM_CPPFLAGS = ${AGENT_INCLUDES}

noinst_PROGRAMS = runag_system

runag_system_SOURCES = runag_system.cc
runag_system_LDADD = ${AGENT_LIBADD}
runag_system_LDFLAGS = 				\
	-Xlinker --whole-archive		\
	../src/libpy2ag_system.la	\
	-Xlinker --no-whole-archive
