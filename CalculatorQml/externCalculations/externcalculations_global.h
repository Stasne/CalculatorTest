#ifndef EXTERNCALCULATIONS_GLOBAL_H
#define EXTERNCALCULATIONS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(EXTERNCALCULATIONS_LIBRARY)
#  define EXTERNCALCULATIONSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define EXTERNCALCULATIONSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // EXTERNCALCULATIONS_GLOBAL_H
