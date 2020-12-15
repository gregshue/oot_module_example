#
# Top level makefile for documentation build
#

BUILDDIR ?= doc/_build
DOC_TAG ?= development
SPHINXOPTS ?= -q

MANIFEST_MODULE_BASE ?= `pwd`
MANIFEST_MODULE_NAME ?= basename $(dirname ${MANIFEST_MODULE_BASE})


# Documentation targets
# ---------------------------------------------------------------------------
clean:
	rm -rf ${BUILDDIR}

htmldocs:
	mkdir -p ${BUILDDIR} && MANIFEST_MODULE_BASE=${MANIFEST_MODULE_BASE} cmake -GNinja -DDOC_TAG=${DOC_TAG} -DSPHINXOPTS=${SPHINXOPTS} -B${BUILDDIR} -Hdoc/ && MANIFEST_MODULE_BASE=${MANIFEST_MODULE_BASE} ninja -C ${BUILDDIR} htmldocs

htmldocs-fast:
	mkdir -p ${BUILDDIR} && MANIFEST_MODULE_BASE=${MANIFEST_MODULE_BASE} cmake -GNinja -DKCONFIG_TURBO_MODE=1 -DDOC_TAG=${DOC_TAG} -DSPHINXOPTS=${SPHINXOPTS} -B${BUILDDIR} -Hdoc/ && MANIFEST_MODULE_BASE=${MANIFEST_MODULE_BASE} ninja -C ${BUILDDIR} htmldocs

pdfdocs:
	mkdir -p ${BUILDDIR} && MANIFEST_MODULE_BASE=${MANIFEST_MODULE_BASE} cmake -GNinja -DDOC_TAG=${DOC_TAG} -DSPHINXOPTS=${SPHINXOPTS} -B${BUILDDIR} -Hdoc/ && MANIFEST_MODULE_BASE=${MANIFEST_MODULE_BASE} ninja -C ${BUILDDIR} pdfdocs

doxygen:
	mkdir -p ${BUILDDIR} && MANIFEST_MODULE_BASE=${MANIFEST_MODULE_BASE} cmake -GNinja -DDOC_TAG=${DOC_TAG} -DSPHINXOPTS=${SPHINXOPTS} -B${BUILDDIR} -Hdoc/ && MANIFEST_MODULE_BASE=${MANIFEST_MODULE_BASE} ninja -C ${BUILDDIR} doxygen
