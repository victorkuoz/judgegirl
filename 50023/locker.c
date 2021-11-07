#include "locker.h"

void init(Lock *lock){
     lock->locked = 0;
     return;
}
int lock(Lock *lock, int combination){
     if ( lock->locked )
          return (-1);
     if ( combination >= 0 && combination <= 9999 ) {
          lock->combination = combination;
          lock->locked = 1;
          return combination;
     }
     return 10000;
}
int unlock(Lock *lock, int combination){
     if ( !lock->locked )
          return (-1);
     if ( combination == lock->combination ) {
          lock->locked = 0;
          return 0;
     }
     return 1;
}
int isLocked(Lock *lock){
     return lock->locked;
}
