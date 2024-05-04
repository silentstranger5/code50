
-- *** The Lost Letter ***
SELECT "id" FROM "addresses" WHERE "address" = '900 Somerville Avenue';
SELECT "id" FROM "addresses" WHERE "address" LIKE '2 Fi%gan Street';
SELECT "id" FROM "packages" WHERE "from_address_id" = (
    SELECT "id" FROM "addresses"
    WHERE "address" = '900 Somerville Avenue'
) AND "to_address_id" = (
    SELECT "id" FROM "addresses"
    WHERE "address" LIKE '2 Fi%igan Street'
);
SELECT "address_id" FROM "scans"
WHERE "package_id" = (
    SELECT "id" FROM "packages"
    WHERE "from_address_id" = (
        SELECT "id" FROM "addresses"
        WHERE "address" = '900 Somerville Avenue'
    ) AND "to_address_id" = (
        SELECT "id" FROM "addresses"
        WHERE "address" LIKE '2 Fi%gan Street'
    )
) AND "action" = 'Drop';
SELECT "type", "address" FROM "addresses"
WHERE "id" = (
    SELECT "address_id" FROM "scans"
    WHERE "package_id" = (
        SELECT "id" FROM "packages"
        WHERE "from_address_id" = (
            SELECT "id" FROM "addresses"
            WHERE "address" = '900 Somerville Avenue'
        ) AND "to_address_id" = (
            SELECT "id" FROM "addresses"
            WHERE "address" LIKE '2 Fi%gan Street'
        )
    ) AND "action" = 'Drop'
);

-- *** The Devious Delivery ***
SELECT "id" FROM "packages" WHERE "from_address_id" IS NULL;
SELECT "address_id" FROM "scans"
WHERE "package_id" = (
    SELECT "id" FROM "packages"
    WHERE "from_address_id" IS NULL
) AND "action" = 'Drop';
SELECT "type" FROM "addresses"
WHERE "id" = (
    SELECT "address_id" FROM "scans"
    WHERE "package_id" = (
        SELECT "id" FROM "packages"
        WHERE "from_address_id" IS NULL
    ) AND "action" = 'Drop'
);
SELECT "contents" FROM "packages"
WHERE "id" = (
    SELECT "id" FROM "packages"
    WHERE "from_address_id" IS NULL
);

-- *** The Forgotten Gift ***
SELECT "id" FROM "addresses" WHERE "address" = '109 Tileston Street';
SELECT "id" FROM "addresses" WHERE "address" = '728 Maple Place';
SELECT "contents" FROM "packages"
WHERE "from_address_id" = (
    SELECT "id" FROM "addresses"
    WHERE "address" = '109 Tileston Street'
) AND "to_address_id" = (
    SELECT "id" FROM "addresses"
    WHERE "address" = '728 Maple Place'
);
SELECT "driver_id" FROM "scans"
WHERE "package_id" = (
    SELECT "id" FROM "packages"
    WHERE "from_address_id" = (
        SELECT "id" FROM "addresses"
        WHERE "address" = '109 Tileston Street'
    ) AND "to_address_id" = (
        SELECT "id" FROM "addresses"
        WHERE "address" = '728 Maple Place'
    )
) AND "action" = 'Pick'
ORDER BY timestamp DESC
LIMIT 1;
SELECT "name" FROM "drivers"
WHERE "id" = (
    SELECT "driver_id" FROM "scans"
    WHERE "package_id" = (
        SELECT "id" FROM "packages"
        WHERE "from_address_id" = (
            SELECT "id" FROM "addresses"
            WHERE "address" = '109 Tileston Street'
        ) AND "to_address_id" = (
            SELECT "id" FROM "addresses"
            WHERE "address" = '728 Maple Place'
        )
    ) AND "action" = 'Pick'
    ORDER BY timestamp DESC
    LIMIT 1
);
