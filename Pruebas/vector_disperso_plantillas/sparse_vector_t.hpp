#pragma once

#include "pair_t.hpp"
#include "vector_pair_t.hpp"
#include "vector_t.hpp"

#include <cmath>

#include <iostream>
#include <iomanip>

using namespace std;



class sparse_vector_t{
private:
	vector_pair_t v_;    // Vector de pares
	int           sz_;          // Tamaño del vector original

public:
	sparse_vector_t(void):
		v_(),
		sz_(0) {}

	sparse_vector_t(const vector_t<double>& v, double eps):
		v_(),
		sz_(v.get_sz()) {
			
		// Cuenta el número de elementos no nulos
		int nz = 0;

		for(int i = 0; i < v.get_sz(); i++)
			if ( is_not_zero(v.get_v(i), eps) )
				nz ++;

		v_.resize(nz);

		nz = 0;

		for(int i = 0; i < v.get_sz(); i++)
			if ( is_not_zero(v.get_v(i), eps) )
			{
				v_.get_set_v(nz).set(i, v.get_v(i));
				nz ++;
			}		

	}

	~sparse_vector_t(void){}

	ostream& write(ostream& os) const{
	
		os << "[ " << setw(7) << sz_ << " ";
		v_.write(os);
		os << " ]";

		return os;
	}

	void scal_prod(const sparse_vector_t& v) const{
		int i=0;
		int j=0;
		int size=0;
	//	cout<<v_.v_[1].get_inx()<<endl;
		if (sz_>=v.sz_) size=sz_;
		if (sz_<v.sz_)  size=v.sz_;
		while((i<size)||(j<size)){
			if(v_.get_v(i).get_inx()==v.v_.get_v(j).get_inx()){ cout<<"entro en el while"<<endl;
			i++;
			}
		}


	}


private:
	bool is_not_zero(double val, double eps){ return fabs(val) > eps;}

};


