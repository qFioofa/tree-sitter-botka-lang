const PREC = {
	DEFAULT: 0,
	STATEMENT: 1,
	BLOCK: 2,
	CONDITION: 3,
	IF_CHAIN: 4,
	ELSE_CLAUSE: 5,
	NUMBER: 6,
	ACTION: 7,
};

module.exports = grammar({
	name: "botka",

	word: ($) => $.identifier,

	extras: ($) => [/\s+/, $.single_line_comment, $.multi_line_comment],

	supertypes: ($) => [$.statement],

	rules: {
		source_file: ($) =>
			seq(
				optional($.program_start),
				repeat($.statement),
				optional($.program_end),
			),

		program_start: ($) => choice("@start", "@начало"),
		program_end: ($) => choice("@end", "@конец"),

		statement: ($) =>
			choice(
				prec.right(PREC.STATEMENT, $.if_statement),
				prec.right(PREC.STATEMENT, $.while_statement),
				prec.right(PREC.STATEMENT, $.for_statement),
				prec.left(PREC.ACTION, $.action_statement),
				$.empty_statement,
			),

		empty_statement: (_) => ";",

		if_statement: ($) =>
			prec.right(
				PREC.IF_CHAIN,
				seq(
					$.if_keyword,
					$.condition,
					$.block,
					repeat($.else_if_clause),
					optional($.else_clause),
				),
			),

		if_keyword: ($) => choice("if", "если"),

		condition: ($) =>
			prec(PREC.CONDITION, seq("(", $.condition_modifier, $.instance, ")")),

		condition_modifier: ($) =>
			choice(seq("{", choice("not", "не"), "}"), seq("{", "}")),

		instance: ($) => choice($.coin_instance, $.obj_instance, $.space_instance),

		coin_instance: ($) => choice("coin", "монета"),
		obj_instance: ($) => choice("obj", "объект"),
		space_instance: ($) => choice("space", "пусто"),

		else_keyword: ($) => choice("else", "иначе"),

		else_if_clause: ($) =>
			prec.right(
				PREC.IF_CHAIN,
				seq($.else_keyword, $.if_keyword, $.condition, $.block),
			),

		else_clause: ($) =>
			prec.right(PREC.ELSE_CLAUSE, seq($.else_keyword, $.block)),

		block: ($) => prec(PREC.BLOCK, seq("{", repeat($.statement), "}")),

		while_statement: ($) =>
			prec.right(PREC.STATEMENT, seq($.while_keyword, $.condition, $.block)),

		while_keyword: ($) => choice("while", "пока"),

		for_statement: ($) =>
			prec.right(PREC.STATEMENT, seq($.for_keyword, $.for_condition, $.block)),

		for_keyword: ($) => choice("for", "для"),

		for_condition: ($) => seq("(", $.positive_number, $.times_keyword, ")"),

		times_keyword: ($) => choice("times", "раз"),

		action_statement: ($) =>
			prec.left(PREC.ACTION, seq($.action_type, $.number, ";")),

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
				prec(
					PREC.NUMBER,
					choice("0", seq(optional(choice("+", "-")), /[1-9][0-9]*/)),
				),
			),

		positive_number: ($) =>
			token(prec(PREC.NUMBER, choice(/[1-9][0-9]*/, seq("+", /[1-9][0-9]*/)))),

		single_line_comment: ($) => token(seq("//", /.*/)),

		multi_line_comment: ($) =>
			token(seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/")),

		identifier: ($) => /[a-zA-Zа-яА-Я_][a-zA-Zа-яА-Я0-9_]*/,
	},
});
