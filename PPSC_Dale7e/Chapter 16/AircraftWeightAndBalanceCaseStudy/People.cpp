//****************************************
// IMPLEMENTATION FILE for People class
//****************************************
#include "People.h"

People::People() {
  Name name(" ", " ", " ");
  role = 'C';
}

//****************************************

People::People(Name initName, char initRole) {
  name = initName;
  role = initRole;
}

//***************************************

Name People::GetName() const { return name; }

//***************************************

char People::GetRole() const { return role; }
