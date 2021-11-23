#include "gtest/gtest.h"
#include "cluster.h"
#include "cluster.cpp"
#include "processor.h"
#include "processor.cpp"

TEST (Cluster, can_create_cluster) {
  ASSERT_NO_THROW (Cluster cl(64));
}

TEST (Cluster, can_create_cluster_with_positive_length) {
  ASSERT_NO_THROW (Cluster cl(5));
}

TEST (Cluster, cant_create_cluster_with_negative_length) {
  ASSERT_ANY_THROW (Cluster cl(-4));
}

TEST (Cluster, cant_crate_cluster_with_to_many_processors) {
  ASSERT_ANY_THROW (Cluster cl(MAX_PROCESSORS_CLUSTER_CONTAINS + 1));
}

TEST (Cluster, free_processors_returns_right_value) {
  Cluster cl(5);
  EXPECT_EQ (5, cl.free_processors());
}

TEST (Cluster, give_makes_cluster_processors_busy) {
  Cluster cl(5);
  cl.give(3, 3);
  EXPECT_EQ (2, cl.free_processors());
} 

TEST (Cluster, update_updates_information_about_free_processors) {
  Cluster cl(5);
  cl.give(2, 1);
  cl.update();
  EXPECT_EQ (5, cl.free_processors());
}

TEST (Cluster, can_assign_cluster_to_itself) {
  Cluster cl1(5);
  ASSERT_NO_THROW (cl1 = cl1);
}

TEST (Cluster, can_assign_clusters) {
  Cluster cl1(5), cl2(5);
  ASSERT_NO_THROW (cl1 = cl2);
}

TEST (Cluster, can_assign_clusters_with_different_amount_of_processors) {
  Cluster cl1(1), cl2(6);
  ASSERT_NO_THROW (cl1 = cl2);
}