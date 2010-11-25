//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_GENERATE_HAS_TYPE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_GENERATE_HAS_TYPE_HPP_INCLUDED

namespace fcppt
{
namespace type_traits
{
/// See http://debugfailure.wordpress.com/2009/10/06/understanding-sfinae/
#define FCPPT_TYPE_TRAITS_GENERATE_HAS_TYPE(mytype)\
	template <typename T>\
	class has_ ## mytype\
	{\
		typedef char true_type;\
		struct false_type{ true_type _[2]; };\
		template <typename U>\
		static true_type check(typename U::mytype *);\
		template <typename U>\
		static false_type check(...);\
		public:\
		static bool const value = sizeof(check<T>(0)) == sizeof(true_type);\
	}
}
}

#endif
