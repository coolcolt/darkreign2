/*
  ImageMagick Progress Monitor Methods.
*/
#ifndef _MONITOR_H
#define _MONITOR_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

/*
  Monitor typedef declarations.
*/
typedef void
  (*MonitorHandler)(const char *,const off_t,const off_t);

/*
  Monitor declarations.
*/
extern Export MonitorHandler
  SetMonitorHandler(MonitorHandler);

extern Export void
  ProgressMonitor(const char *,const off_t,const off_t);

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
