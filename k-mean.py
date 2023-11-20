import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler
data = pd.read_csv('sales_data_sample.csv', encoding='latin1')

scaler = StandardScaler()
scaled_data=scaler.fit_transform(data[['SALES','QUANTITYORDERED']]);


cluster = []

for i in range(1,10):
    kmean = KMeans(n_clusters = i);
    kmean.fit(scaled_data)
    cluster.append(kmean.inertia_);



# plot elbow

plt.plot(range(1,10),cluster,'bx-')
plt.title("Elbow method")
plt.xlabel("k")
plt.ylabel("data")
plt.show();


optimal_k = 3;
km = KMeans(n_clusters=3);
data['cluster']=km.fit_predict(scaled_data);




for cluster in range(optimal_k):
    plt.scatter(data[data['cluster'] == cluster]['QUANTITYORDERED'], data[data['cluster'] == cluster]['SALES'], label=f'cluster {cluster}')
plt.title(f'K-Means Clustering with {optimal_k} cluster')
plt.xlabel('QUANTITYORDERED')
plt.ylabel('SALES')
plt.legend()
plt.show()
















# # Step 2: Data Preprocessing
# # (Include preprocessing steps like handling missing values and encoding categorical variables if needed)

# # Step 3: Feature Selection
# # Select relevant features for clustering (e.g., 'Quantity' and 'Revenue')
# # Step 4: Scaling
# scaler = StandardScaler()
# scaled_data = scaler.fit_transform(data[['QUANTITYORDERED', 'SALES']])
# # Step 5: K-Means Clustering and Elbow Method
# wcss = []  # Within-cluster sum of squares
# for k in range(1, 11):  # Trying k values from 1 to 10
#     kmeans = KMeans(n_clusters=k, random_state=0)
#     kmeans.fit(scaled_data)
#     wcss.append(kmeans.inertia_)

# # Step 6: Elbow Method
# plt.figure(figsize=(8, 6))
# plt.plot(range(1, 11), wcss, marker='o', linestyle='-', color='b')
# plt.title('Elbow Method')
# plt.xlabel('Number of Clusters (k)')
# plt.ylabel('WCSS')
# plt.show()

# # Step 6 (cont'd): Determine the optimal number of clusters from the plot
# # Step 7: Cluster Visualization
# # Re-run K-Means with the chosen number of clusters and visualize the clusters
# optimal_k = 3  # Choose the optimal k from the elbow method
# kmeans = KMeans(n_clusters=optimal_k, random_state=0)
# data['Cluster'] = kmeans.fit_predict(scaled_data)
# # Visualize the clusters (for example, with scatter plots)
# plt.figure(figsize=(8, 6))
# for cluster in range(optimal_k):
#     plt.scatter(data[data['Cluster'] == cluster]['QUANTITYORDERED'], data[data['Cluster'] == cluster]['SALES'], label=f'Cluster {cluster}')
# plt.title(f'K-Means Clustering with {optimal_k} Clusters')
# plt.xlabel('QUANTITYORDERED')
# plt.ylabel('SALES')
# plt.legend()
# plt.show()

