#pragma once
#include "Devise.h"

namespace Banque {
	class Dollar :
		public Devise
	{
	private:
		
		double static taux_DeChange_Mad;
		double static taux_DeChange_euro;
	public:
		Dollar(double val);
		void afficher() const;
		MAD& convert_to_MAD();
		Dollar& convert_to_Dollar();
		Euro& convert_to_euro();
	};
}
