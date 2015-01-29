function(
	add_fcppt_test
	PATHNAME
)
	set(
		MULTI_ARGS
		LINK_LIBS
	)

	cmake_parse_arguments(
		""
		""
		""
		"${MULTI_ARGS}"
		${ARGN}
	)

	fcppt_utils_add_test(
		"${PATHNAME}"
		LINK_LIBS
			${_LINK_LIBS}
	)
endfunction()


fcppt_link_target(
	fcppt_core
)

fcppt_link_target(
	fcppt_filesystem
)

fcppt_link_target(
	fcppt_log
)


add_fcppt_test(
	algorithm/array_init_move
)

add_fcppt_test(
	algorithm/array_push_back
)

add_fcppt_test(
	algorithm/enum_array_fold
)

add_fcppt_test(
	algorithm/find_if_exn
)

add_fcppt_test(
	algorithm/find_if_opt
)

add_fcppt_test(
	algorithm/fold
)

add_fcppt_test(
	algorithm/join
)

add_fcppt_test(
	algorithm/join_move
)

add_fcppt_test(
	algorithm/levenshtein
)

add_fcppt_test(
	algorithm/map
)

add_fcppt_test(
	algorithm/map_concat
)

add_fcppt_test(
	algorithm/map_optional
)

add_fcppt_test(
	algorithm/remove
)

add_fcppt_test(
	algorithm/repeat
)

add_fcppt_test(
	algorithm/set_intersection
)

add_fcppt_test(
	algorithm/shift_compare
)

add_fcppt_test(
	assert
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	assign/make_container
)

add_fcppt_test(
	assign/make_container_opt
)

add_fcppt_test(
	assign/make_map
)

add_fcppt_test(
	cast_to_enum
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	cast/promote
)

add_fcppt_test(
	codecvt
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	container/bitfield
)

add_fcppt_test(
	container/data
)

add_fcppt_test(
	container/enum_array
)

add_fcppt_test(
	container/find_exn
)

add_fcppt_test(
	container/get_or_insert
)

add_fcppt_test(
	container/grid
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	container/grid/moore_neighbors
)

add_fcppt_test(
	container/grid/neumann_neighbors
)

add_fcppt_test(
	container/grid/spiral_range
)

add_fcppt_test(
	container/index_map
)

add_fcppt_test(
	container/raw_vector
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	container/tree/copy
)

add_fcppt_test(
	container/tree/depth
)

add_fcppt_test(
	container/tree/equal
)

add_fcppt_test(
	container/tree/level
)

add_fcppt_test(
	container/tree/map
)

add_fcppt_test(
	container/tree/move
)

add_fcppt_test(
	container/tree/pre_order
)

add_fcppt_test(
	container/tree/print
)

add_fcppt_test(
	container/tree/swap
)

add_fcppt_test(
	cyclic_iterator
)

add_fcppt_test(
	endianness
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	enum_range
)

add_fcppt_test(
	extract_from_string
)

add_fcppt_test(
	filesystem/remove_extension
	LINK_LIBS
		"${fcppt_filesystem_TARGET}"
)

add_fcppt_test(
	homogenous_pair
)

add_fcppt_test(
	insert_to_string
)

add_fcppt_test(
	int_range
)

add_fcppt_test(
	io/read_write
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	io/stream_to_string
)

add_fcppt_test(
	io/raw_container_source
)

add_fcppt_test(
	literal
)

add_fcppt_test(
	log/context_transfer
	LINK_LIBS
		 "${fcppt_core_TARGET};${fcppt_log_TARGET}"
)

add_fcppt_test(
	math/bresenham
)

add_fcppt_test(
	math/ceil_div
)

add_fcppt_test(
	math/circle
)

add_fcppt_test(
	math/dim
)

add_fcppt_test(
	math/binary_vectors
)

add_fcppt_test(
	math/interpolation
)

add_fcppt_test(
	math/is_power_of_2
)

add_fcppt_test(
	math/vector
)

add_fcppt_test(
	math/units
)

add_fcppt_test(
	math/util
)

add_fcppt_test(
	math/box/center
)

add_fcppt_test(
	math/box/corner_points
)

add_fcppt_test(
	math/box/extend
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	math/box/intersection
)

add_fcppt_test(
	math/box/stretch
)

add_fcppt_test(
	math/box/structure_cast
)

add_fcppt_test(
	math/matrix/access
)

add_fcppt_test(
	math/matrix/adjugate
)

add_fcppt_test(
	math/matrix/delete_column_and_row
)

add_fcppt_test(
	math/matrix/determinant
)

add_fcppt_test(
	math/matrix/exponential_pade
)

add_fcppt_test(
	math/matrix/has_dim
)

add_fcppt_test(
	math/matrix/hash
)

add_fcppt_test(
	math/matrix/infinity_norm
)

add_fcppt_test(
	math/matrix/inverse
)

add_fcppt_test(
	math/matrix/is_matrix
)

add_fcppt_test(
	math/matrix/logarithm
)

add_fcppt_test(
	math/matrix/multiply
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	math/matrix/operators
)

add_fcppt_test(
	math/matrix/rotation_axis
)

add_fcppt_test(
	math/matrix/rotation_x
)

add_fcppt_test(
	math/matrix/scaling
)

add_fcppt_test(
	math/matrix/translation
)

add_fcppt_test(
	math/matrix/view
)

add_fcppt_test(
	math/vector/distance
)

add_fcppt_test(
	math/vector/hash
)

add_fcppt_test(
	math/vector/raw_view
)

add_fcppt_test(
	math/vector/unit
)

add_fcppt_test(
	math/vector/view_storage
)

add_fcppt_test(
	mpl/all_of
)

add_fcppt_test(
	mpl/append
)

add_fcppt_test(
	mpl/ceil_div
)

add_fcppt_test(
	optional
)

add_fcppt_test(
	reference_wrapper
)

add_fcppt_test(
	runtime_enum
)

add_fcppt_test(
	scoped_state_machine
)

add_fcppt_test(
	shared_ptr
)

add_fcppt_test(
	signal/simple
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	signal/unregister
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	strong_typedef
)

add_fcppt_test(
	truncation_check_cast
	LINK_LIBS
		"${fcppt_core_TARGET}"
)

add_fcppt_test(
	type_traits/is_iterator
)

add_fcppt_test(
	type_traits/members
)

add_fcppt_test(
	unique_ptr
)

add_fcppt_test(
	variant/apply_movable
)

add_fcppt_test(
	variant/apply_nonconst
)

add_fcppt_test(
	variant/apply_prvalue
)

add_fcppt_test(
	variant/assign
)

add_fcppt_test(
	variant/compare
)

add_fcppt_test(
	variant/equal
)

add_fcppt_test(
	variant/exception
)

add_fcppt_test(
	variant/get
)

add_fcppt_test(
	variant/holds_type
)

add_fcppt_test(
	variant/less
)

add_fcppt_test(
	variant/move
)
