CREATE TABLE "ingredients" (
    "id" INTEGER,
    "name" TEXT NOT NULL UNIQUE,
    "price" REAL NOT NULL,
    PRIMARY KEY ("id")
);

CREATE TABLE "donuts" (
    "id" INTEGER,
    "name" TEXT NOT NULL,
    "gluten_free" INTEGER NOT NULL,
    "price" REAL NOT NULL,
    PRIMARY KEY ("id")
);

CREATE TABLE "donut_ingredients" (
    "id" INTEGER,
    "donut_id" INTEGER,
    "ingredient_id" INTEGER,
    PRIMARY KEY ("id"),
    FOREIGN KEY ("donut_id") REFERENCES "donuts" ("id"),
    FOREIGN KEY ("ingredient_id") REFERENCES "ingredients" ("id")
);

CREATE TABLE "orders" (
    "id" INTEGER,
    "customer_id" INTEGER,
    PRIMARY KEY ("id"),
    FOREIGN KEY ("customer_id") REFERENCES "customers" ("id")
);

CREATE TABLE "order_donuts" (
    "id" INTEGER,
    "order_id" INTEGER,
    "donut_id" INTEGER,
    "donut_number" INTEGER NOT NULL CHECK ("donut_number" > 0),
    PRIMARY KEY ("id"),
    FOREIGN KEY ("order_id") REFERENCES "orders" ("id"),
    FOREIGN KEY ("donut_id") REFERENCES "donuts" ("id")
);

CREATE TABLE "customers" (
    "id" INTEGER,
    "first_name" TEXT NOT NULL,
    "last_name" TEXT NOT NULL,
    PRIMARY KEY ("id")
);

CREATE TABLE "customer_orders" (
    "id" INTEGER,
    "customer_id" INTEGER,
    "order_id" INTEGER,
    PRIMARY KEY ("id"),
    FOREIGN KEY ("customer_id") REFERENCES "customers" ("id"),
    FOREIGN KEY ("order_id") REFERENCES "orders" ("id")
);
