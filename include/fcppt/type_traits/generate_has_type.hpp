//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_GENERATE_HAS_TYPE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_GENERATE_HAS_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/bool.hpp>
#include <fcppt/config/external_end.hpp>

/**
\brief Generates a type trait that checks if a class has a given type

\ingroup fcppttypetraits

Given \a mytype, generates a type trait called <code>has_ ## mytype</code>.
This type trait takes one template parameter, which should be checked if it has
a type called \a mytype.

\snippet examples/type_traits.cpp generate_has_type

See http://debugfailure.wordpress.com/2009/10/06/understanding-sfinae/
*/
#define FCPPT_TYPE_TRAITS_GENERATE_HAS_TYPE(\
	mytype\
)\
	template <typename T>\
	class has_ ## mytype ## _impl\
	{\
		typedef char true_type;\
		struct false_type{ true_type _[2]; };\
		template <typename U>\
		static true_type check(typename U::mytype *);\
		template <typename U>\
		static false_type check(...);\
	public:\
		typedef boost::mpl::bool_<\
			sizeof(check<T>(0)) == sizeof(true_type)\
		> type;\
	};\
\
	template<typename T>\
	struct has_ ## mytype\
	:\
		has_ ## mytype ## _impl<\
			T\
		>::type\
	{\
	}

#endif
