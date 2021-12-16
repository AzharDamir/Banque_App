#pragma once
#pragma once
#include "Operation.h"
#include <iostream>
using namespace std;
namespace Banque {
    class OperationA :
        public Operation
    {
    public:
        OperationA(Devise* montant, Compte* c, Date* d);
        void afficher_op() const;

    private:
        static string libel;
    };
}