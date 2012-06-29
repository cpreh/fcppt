//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ARRAY_ADAPTER_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ARRAY_ADAPTER_HPP_INCLUDED

#define FCPPT_MATH_DETAIL_ARRAY_ADAPTER(\
	name\
)\
	pointer \
	data(); \
\
	const_pointer \
	data() const; \
\
	reference \
	at(\
		size_type\
	);\
\
	const_reference \
	at(\
		size_type\
	) const;\
\
	iterator \
	begin();\
\
	const_iterator \
	begin() const;\
\
	iterator \
	end();\
\
	const_iterator \
	end() const;\
\
	reverse_iterator \
	rbegin();\
\
	const_reverse_iterator \
	rbegin() const;\
\
	reverse_iterator \
	rend();\
\
	const_reverse_iterator \
	rend() const;\
\
	reference \
	back();\
\
	const_reference \
	back() const;\
\
	reference \
	front();\
\
	const_reference \
	front() const;\
\
	bool \
	empty() const;\
\
	size_type \
	size() const;

#endif
