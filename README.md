
# E-Market

## Introduction
E-Market is an online market system built using Qt. It consists of a server that manages product and user databases and clients that allow users to browse and purchase products. The server ensures real-time updates and secure user sessions, while the client provides a user-friendly interface for shopping.

## Project Architecture
### General
- **Server-Client Architecture:** The server holds all the product and user information and handles requests from clients using TCP for reliable communication.
- **Multithreading:** The server uses multithreading to handle multiple users simultaneously, ensuring smooth interactions and real-time updates across all active users. Each user connection is managed by a separate thread.

## Client Functionality
### User Interface
- **Login/Signup:** Users are greeted with a login screen where they can log in or sign up. All new accounts have the "user" authority level. Admin accounts are created on the server.
- **Product Browsing:** After logging in, users can browse products divided into 8 categories: fruits, vegetables, canned products, cold cuts, cleaning products, clothes, snacks, and dairy products. Each product has details like category, id, name, price, and available quantity, all laid out in a table for easy browsing.
- **Add to Cart:** Users can add products to their cart based on available quantities. The system ensures they cannot add more than the available stock.
- **Checkout:** Users proceed to checkout by providing their address, email, and phone number. They can save this data to their account for future use. If no address is saved and none is provided, the checkout cannot be completed. Upon successful checkout, an invoice is generated and saved as a PDF both in the server and on the user's device. The cart is then emptied, and product quantities are updated across all active users.

## Server Functionality
### Security and Session Management
- **Single Device Login:** Accounts can only be active on one device at a time. Users must sign out before using their account on a different device.
### Automated Invoicing
- **Invoice Generation:** Upon successful checkout, an invoice is generated and saved as a PDF on both the server and the user's device. The invoice contains detailed information about the user and the products ordered.
### Admin Capabilities
- **Product Management:** Admin users can add or remove products, ensuring the market database is always up-to-date. Any changes made by the admin are immediately reflected across all active users.
### Request Handling
The server efficiently handles various requests from users:
- **Login:** Returns success and account authority, or errors if the account is in use or doesn’t exist.
- **Signout:** Makes the account available for signing in again.
- **Database Request:** Returns the product database.
- **Checkout:** Updates the database, subtracts ordered products, generates an invoice, and sends it to the user.
- **Signup:** Creates a new account unless one with the same username already exists.
- **Save Address:** Saves the user's address to their account.
- **Get Address:** Returns the saved address for the user.
- **New Product:** Adds a new product to the database (admin only).
- **Delete Product:** Deletes a product from the database (admin only).

## Conclusion
E-Market is a comprehensive and user-friendly online market platform that demonstrates the capabilities of Qt in developing dynamic and secure applications. The combination of a robust server-client architecture, secure session management, real-time updates, and detailed invoicing ensures a smooth and efficient shopping experience for users. Enjoy shopping with E-Market!

## Installation and Setup
1. **Clone the Repository:** `git clone https://github.com/your-repo/e-market.git`
2. **Run the Server:** Navigate to the server directory and run the server application.
3. **Run the Client:** Navigate to the client directory and run the client application.

## Usage
- **Login/Signup:** Start by creating a new user account or logging in with an existing one.
- **Browse Products:** Once logged in, browse through the available products and add desired items to your cart.
- **Checkout:** Proceed to checkout, enter your address, email, and phone number, and place your order.
- **Admin Access:** Log in as an admin to manage the product database.

---

Feel free to reach out if you have any questions or need further assistance. Enjoy shopping with E-Market!
