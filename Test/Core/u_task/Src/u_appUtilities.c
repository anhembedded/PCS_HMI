#include "u_appUtilities.h"

portBASE_TYPE isTaskSuspended(xTaskHandle taskHandle) {
  portBASE_TYPE taskStatus = eBlocked;
  portBASE_TYPE res = 0;
  taskStatus = eTaskGetState(taskHandle);
  if (taskStatus == eSuspended) {
    res = 1;
  } else {
    res = 0;
  }
  return (res);
}

portBASE_TYPE isTaskRunOrReady(xTaskHandle taskHandle) {
  portBASE_TYPE taskStatus;
  portBASE_TYPE res = 0;
  taskStatus = eTaskGetState(taskHandle);
  if ((taskStatus != eReady) || (taskStatus != eRunning)) {
    res = 1;
  } else {
    res = 0;
  }
  return (res);
}
