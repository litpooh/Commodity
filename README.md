# Commodity Inventory System
## ENGG1340 18-19 2nd Sem
### Problem Statement
As a business expands its scale, it would be inefficient to manage inventories with just human efforts as the system also grows bigger, and errors are easily made owing to its increasing complexity. In addition, business owners often need to consider the reordering amount and they may make mistakes by chance, which would lead to the loss of a considerable sum of money.
   
By using an inventory management system, businesses can manage their inventories in a more efficient manner, thus reduce the cost of maintaining a quality record. Moreover, with the help of a reordering amount reminder, they may lower the potential loss, which also implies higher profit.

### Problem Setting
1. Number of shops: 4
2. Stock level
   - Out-of-stock (stock = 0)
   - Low (stock <= 0.3 × demand)
   - Normal (in between)
   - Excess (stock > 1.3 × demand)

### Features
1. *Search by Filters*
   - Retrieve the information (e.g. stocks, manufacturer, price) **faster**
     - Compared with searching in printed record or manual counting
2. *Insert, Update, Delete Record with **Ease***
3. *Auto Stock Status Update*
   - Out-of-stock / Low / Normal / Excess
   - Respective **advice** for different status
   - After the user update the inventory, the status will be updated when running the program again
4. *Auto Alert*
   - Reordering: Show commodities that need reordering (out-of-stock or low stock level)
   - Surplus: Show commodities that may need promotion and shouldn't be reordered (excess stock level)
   - Increase the **efficiency** of the reordering process without the worry of missed items
5. *Auto Price Calculator*
   - Calculate labeled price based on user input
   - Save effort setting prices
6. *Demand Forecast* (based on weighted mean)
   - Use recent historical data for more precise prediction
   - Displayed along with reorder alert
   - Help businesses decide the amount of commodities to stock up
   - Serve as a reference for planning sales tactics
   - Prevent overstocking and understocking ––> **maximize profit**
   
### Instructions
1. Building the System
   - Type `make main` in the terminal
2. *Searching:*
   - User can enter any filter for searching (name, tag, price range, whether it's available in a certain shop, .etc)
   - Performing nested search, the range of searching will be retricted to the previous search results
3. *Inserting, Updating, Deleting:*
   - **A Must**: the name of the product, users can refer to the search section
   - All items are compared against the record to avoid duplicates, and to ensure valid actions
   - Continous insert/update/delete can be done by entering 'C' option
   - For newly inserted items, the status will be NA (as it does not have ant sales record) until first negative change in          inventory
4. *Demand and Status:*
   - User are not abled to updating the demand and status of a item
   - If there is any change in inventory, the system will check and update demand and status if necessary
   - The demand is calculated when the system is launched
     - No instant effect seen after updating certain record ––> restart the system
5. User-friendly system
   - *Case Insensitive*
     - Input terms with only case difference is recognized
   - *Return Option*
     - Implemented in many parts of the system
   - *Guidelines*
     - Detailed guidelines inside the system in different sections
6. Requiremnt
   - Test files should be put in the same directory as the system
