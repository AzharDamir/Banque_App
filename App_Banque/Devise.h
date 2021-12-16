#pragma once
namespace Banque {
	class MAD;
	class Euro;
	class Dollar;
	class Devise
	{
	private:
		double valeur;
	public:
		Devise(double val);
		Devise& operator+(const Devise& M);
		Devise& operator-(const Devise& M);
		Devise& operator*(const Devise& M);
		Devise& operator*(double const M);
		Devise& operator/(double const val);
		bool operator<=(const Devise& M)const;
		bool operator>=(const Devise& M) const;
		virtual void afficher() const;
		virtual MAD& convert_to_MAD() = 0;
		virtual Dollar& convert_to_Dollar()  = 0;
		virtual Euro& convert_to_euro() = 0;
		double convert_to_double(double) const;
		bool check_solde(Devise* M, Devise* N);
		bool check_moitier(Devise* D) const;
	};
};

