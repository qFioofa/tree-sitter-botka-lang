module.exports = grammar({
	name: "botka",

	word: ($) => $.identifier,

	extras: ($) => [/[ \t\r\n]+/],

	rules: {
		source_file: ($) =>
			seq(
				repeat($._top_level_item),
				optional($.program_start),
				repeat($._program_content),
				optional($.program_end),
				repeat($._top_level_item),
			),

		program_start: ($) => choice("@start", "@начало"),

		program_end: ($) => choice("@end", "@конец"),

		_top_level_item: ($) => choice($.single_line_comment, $.multi_line_comment),

		_program_content: ($) =>
			choice(
				$.single_line_comment,
				$.multi_line_comment,
				$.if_statement,
				$.while_statement,
				$.for_statement,
				$.action_statement,
				$.program_error_parsing,
			),

		program_error_parsing: ($) => prec(-1, token(/[a-zA-Zа-яА-Я0-9_]+/)),

		// IF STATEMENT
		if_statement: ($) =>
			seq(
				$.if_keyword,
				$.condition,
				$.block,
				optional($.else_if_chain),
				optional($.else_clause),
			),

		if_keyword: ($) => choice("if", "если"),

		condition: ($) => seq("(", $.condition_modifier, $.instance, ")"),

		condition_modifier: ($) =>
			choice(seq("{", "not", "}"), seq("{", "не", "}"), seq("{", "}")),

		instance: ($) => choice($.coin_instance, $.obj_instance, $.space_instance),

		coin_instance: ($) => choice("coin", "монета"),
		obj_instance: ($) => choice("obj", "объект"),
		space_instance: ($) => choice("space", "пусто"),

		else_if_chain: ($) => repeat1($.else_if_clause),

		else_if_clause: ($) =>
			seq($.else_keyword, $.if_keyword, $.condition, $.block),

		else_keyword: ($) => choice("else", "иначе"),

		else_clause: ($) => seq($.else_keyword, $.block),

		block: ($) => seq("{", repeat($._program_content), "}", optional(";")),

		// WHILE STATEMENT
		while_statement: ($) => seq($.while_keyword, $.condition, $.block),

		while_keyword: ($) => choice("while", "пока"),

		// FOR STATEMENT
		for_statement: ($) => seq($.for_keyword, $.for_condition, $.block),

		for_keyword: ($) => choice("for", "для"),

		for_condition: ($) => seq("(", $.positive_number, $.times_keyword, ")"),

		times_keyword: ($) => choice("times", "раз"),

		positive_number: ($) =>
			token(choice(/[1-9][0-9]*/, seq("+", /[1-9][0-9]*/))),

		// ACTION STATEMENT
		action_statement: ($) => seq($.action_type, $.number, ";"),

		action_type: ($) =>
			choice(
				$.forward_action,
				$.backwards_action,
				$.right_action,
				$.left_action,
			),

		forward_action: ($) => choice("forward", "вперед"),
		backwards_action: ($) => choice("backwards", "назад"),
		right_action: ($) => choice("right", "вправо"),
		left_action: ($) => choice("left", "влево"),

		number: ($) =>
			token(
				choice(
					seq(optional(choice("+", "-")), /[1-9][0-9]*/),
					seq(choice("+", "-"), /[1-9][0-9]*/),
					"0",
				),
			),

		single_line_comment: ($) => token(seq("//", /.*/)),

		multi_line_comment: ($) =>
			token(seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/")),

		identifier: ($) => /[a-zA-Zа-яА-Я_][a-zA-Zа-яА-Я0-9_]*/,
	},
});
