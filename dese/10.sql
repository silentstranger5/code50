SELECT "name", "per_pupil_expenditure" FROM "districts"
JOIN "expenditures" ON "districts"."id" = "expenditures"."district_id"
WHERE "name" NOT LIKE '%(District)'
ORDER BY "per_pupil_expenditure" DESC
LIMIT 10;